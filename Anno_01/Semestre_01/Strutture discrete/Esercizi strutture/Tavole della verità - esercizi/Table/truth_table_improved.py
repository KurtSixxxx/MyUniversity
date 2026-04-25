import itertools
import re
import tkinter as tk
from tkinter import ttk, messagebox
from typing import List, Dict, Set

class TruthTableGenerator:
    def __init__(self):
        self.variables = set()
        
    def extract_variables(self, expression: str) -> Set[str]:
        clean_expr = expression.replace(' ', '')
        variables = re.findall(r'[a-z]', clean_expr)
        return set(variables)
    
    def parse_tex_to_unicode(self, tex_expr: str) -> str:
        tex_expr = tex_expr.replace('\\neg', '¬')
        tex_expr = tex_expr.replace('\\land', '∧')
        tex_expr = tex_expr.replace('\\lor', '∨')
        tex_expr = tex_expr.replace('\\vee', '∨')
        tex_expr = tex_expr.replace('\\iff', '↔')
        tex_expr = tex_expr.replace('\\implies', '→')
        return tex_expr
    
    def parse_expression(self, expr: str) -> str:
        expr = self.handle_implications(expr)
        expr = expr.replace('¬', 'not ')
        expr = expr.replace('∨', ' or ')
        expr = expr.replace('∧', ' and ')
        return expr
    
    def handle_implications(self, expr: str) -> str:
        while '↔' in expr:
            pos = expr.find('↔')
            left_part, right_part = self.extract_operands(expr, pos)
            replacement = f"(({left_part}) and ({right_part})) or ((not ({left_part})) and (not ({right_part})))"
            start_pos = pos - len(left_part)
            end_pos = pos + 1 + len(right_part)
            expr = expr[:start_pos] + replacement + expr[end_pos:]
        
        while '→' in expr:
            pos = expr.find('→')
            left_part, right_part = self.extract_operands(expr, pos)
            replacement = f"((not ({left_part})) or ({right_part}))"
            start_pos = pos - len(left_part)
            end_pos = pos + 1 + len(right_part)
            expr = expr[:start_pos] + replacement + expr[end_pos:]
        
        return expr
    
    def extract_operands(self, expr: str, op_pos: int) -> tuple:
        left_end = op_pos - 1
        if expr[left_end] == ')':
            paren_count = 1
            left_start = left_end - 1
            while left_start >= 0 and paren_count > 0:
                if expr[left_start] == ')':
                    paren_count += 1
                elif expr[left_start] == '(':
                    paren_count -= 1
                left_start -= 1
            left_start += 1
        else:
            left_start = left_end
            while left_start > 0 and (expr[left_start-1].isalnum() or expr[left_start-1] == '¬'):
                left_start -= 1
        
        left_part = expr[left_start:op_pos].strip()
        
        right_start = op_pos + 1
        if expr[right_start] == '(':
            paren_count = 1
            right_end = right_start + 1
            while right_end < len(expr) and paren_count > 0:
                if expr[right_end] == '(':
                    paren_count += 1
                elif expr[right_end] == ')':
                    paren_count -= 1
                right_end += 1
            right_end -= 1
        else:
            right_end = right_start
            while right_end < len(expr) - 1 and (expr[right_end+1].isalnum() or expr[right_end+1] == '¬'):
                right_end += 1
        
        right_part = expr[right_start:right_end+1].strip()
        return left_part, right_part
    
    def evaluate_expression(self, expr: str, values: Dict[str, bool]) -> bool:
        for var, val in values.items():
            expr = expr.replace(var, str(val))
        try:
            return eval(expr)
        except:
            return False
    
    def generate_subexpressions(self, main_expr: str) -> List[str]:
        subexpressions = []
        for var in sorted(self.variables):
            subexpressions.append(var)
            subexpressions.append(f'¬{var}')
        
        self.extract_subexpressions_recursive(main_expr, subexpressions)
        
        seen = set()
        unique_subexpressions = []
        for expr in subexpressions:
            if expr not in seen:
                seen.add(expr)
                unique_subexpressions.append(expr)
        
        return unique_subexpressions
    
    def extract_subexpressions_recursive(self, expr: str, subexpressions: List[str]):
        i = 0
        while i < len(expr):
            if expr[i] == '(':
                paren_count = 1
                j = i + 1
                while j < len(expr) and paren_count > 0:
                    if expr[j] == '(':
                        paren_count += 1
                    elif expr[j] == ')':
                        paren_count -= 1
                    j += 1
                
                if paren_count == 0:
                    inner_expr = expr[i+1:j-1]
                    if inner_expr and inner_expr not in subexpressions:
                        subexpressions.append(inner_expr)
                        self.extract_subexpressions_recursive(inner_expr, subexpressions)
                i = j
            else:
                i += 1
        
        operators = ['↔', '→', '∧', '∨']
        for op in operators:
            if op in expr:
                parts = self.split_by_operator(expr, op)
                if len(parts) > 1:
                    current = parts[0]
                    for i in range(1, len(parts)):
                        current = current + f' {op} ' + parts[i]
                        if current not in subexpressions and current != expr:
                            subexpressions.append(current)
                break
    
    def split_by_operator(self, expr: str, operator: str) -> List[str]:
        parts = []
        current_part = ""
        paren_count = 0
        i = 0
        
        while i < len(expr):
            if expr[i] == '(':
                paren_count += 1
                current_part += expr[i]
            elif expr[i] == ')':
                paren_count -= 1
                current_part += expr[i]
            elif expr[i:i+len(operator)] == operator and paren_count == 0:
                parts.append(current_part.strip())
                current_part = ""
                i += len(operator) - 1
            else:
                current_part += expr[i]
            i += 1
        
        if current_part.strip():
            parts.append(current_part.strip())
        
        return parts
    
    def generate_truth_table_data(self, expression: str):
        self.variables = self.extract_variables(expression)
        n_vars = len(self.variables)
        
        subexpressions = self.generate_subexpressions(expression)
        if expression not in subexpressions:
            subexpressions.append(expression)
        
        var_list = sorted(self.variables)
        combinations = list(itertools.product([False, True], repeat=n_vars))
        
        table_data = []
        for combination in combinations:
            values = dict(zip(var_list, combination))
            row = []
            for subexpr in subexpressions:
                parsed_expr = self.parse_expression(subexpr)
                result = self.evaluate_expression(parsed_expr, values)
                row.append(result)
            table_data.append(row)
        
        return subexpressions, table_data

class ModernButton(tk.Frame):
    def __init__(self, parent, text, command, bg_color="#4A90E2", hover_color="#357ABD", **kwargs):
        super().__init__(parent, **kwargs)
        
        self.command = command
        self.bg_color = bg_color
        self.hover_color = hover_color
        
        self.button = tk.Label(self, text=text, bg=bg_color, fg="white", 
                              font=("Segoe UI", 10, "bold"), cursor="hand2",
                              padx=15, pady=8, relief="flat")
        self.button.pack(fill="both", expand=True)
        
        self.button.bind("<Button-1>", lambda e: self.command())
        self.button.bind("<Enter>", self.on_enter)
        self.button.bind("<Leave>", self.on_leave)
    
    def on_enter(self, event):
        self.button.config(bg=self.hover_color)
    
    def on_leave(self, event):
        self.button.config(bg=self.bg_color)
    
    def update_colors(self, bg_color, hover_color):
        self.bg_color = bg_color
        self.hover_color = hover_color
        self.button.config(bg=bg_color)

class TruthTableGUI:
    def __init__(self, root):
        self.root = root
        self.root.title("Truth Table Generator")
        self.root.geometry("1200x800")
        
        # Theme management
        self.is_dark_theme = False
        self.themes = {
            'light': {
                'bg': "#f8f9fa",
                'card_bg': "#ffffff",
                'header_bg': "#2c3e50",
                'header_fg': "white",
                'text_primary': "#2c3e50",
                'text_secondary': "#7f8c8d",
                'input_bg': "#fafafa",
                'info_bg': "#e8f4fd",
                'table_header_bg': "#34495e",
                'table_even_row': "#ecf0f1",
                'table_odd_row': "#ffffff",
                'border_color': "#bdc3c7"
            },
            'dark': {
                'bg': "#1a1a1a",
                'card_bg': "#2d2d2d",
                'header_bg': "#0d1117",
                'header_fg': "#f0f6fc",
                'text_primary': "#f0f6fc",
                'text_secondary': "#8b949e",
                'input_bg': "#21262d",
                'info_bg': "#161b22",
                'table_header_bg': "#21262d",
                'table_even_row': "#161b22",
                'table_odd_row': "#0d1117",
                'border_color': "#30363d"
            }
        }
        
        self.current_theme = self.themes['light']
        self.root.configure(bg=self.current_theme['bg'])
        
        # Stile moderno
        self.setup_styles()
        
        self.generator = TruthTableGenerator()
        self.setup_gui()
        
    def setup_styles(self):
        style = ttk.Style()
        style.theme_use('clam')
        style.configure('Modern.TNotebook', 
                       background=self.current_theme['card_bg'], 
                       borderwidth=0)
        style.configure('Modern.TNotebook.Tab', 
                       padding=[20, 10], 
                       font=("Segoe UI", 11),
                       background=self.current_theme['card_bg'],
                       foreground=self.current_theme['text_primary'])
        
    def toggle_theme(self):
        self.is_dark_theme = not self.is_dark_theme
        self.current_theme = self.themes['dark'] if self.is_dark_theme else self.themes['light']
        
        # Update root
        self.root.configure(bg=self.current_theme['bg'])
        
        # Update styles
        self.setup_styles()
        
        # Update all widgets
        self.update_theme_recursive(self.root)
        
        # Update theme button text
        theme_text = "☀️ Light Theme" if self.is_dark_theme else "🌙 Dark Theme"
        self.theme_button.button.config(text=theme_text)
        
    def update_theme_recursive(self, widget):
        widget_class = widget.winfo_class()
        
        if widget_class == 'Frame':
            if widget == self.header:
                widget.config(bg=self.current_theme['header_bg'])
            elif hasattr(widget, 'is_card_frame') and widget.is_card_frame:
                widget.config(bg=self.current_theme['card_bg'])
            elif hasattr(widget, 'is_info_frame') and widget.is_info_frame:
                widget.config(bg=self.current_theme['info_bg'])
            else:
                widget.config(bg=self.current_theme['bg'])
                
        elif widget_class == 'Label':
            if widget == self.title_label:
                widget.config(bg=self.current_theme['header_bg'], 
                             fg=self.current_theme['header_fg'])
            elif hasattr(widget, 'label_type'):
                if widget.label_type == 'primary':
                    widget.config(fg=self.current_theme['text_primary'])
                elif widget.label_type == 'secondary':
                    widget.config(fg=self.current_theme['text_secondary'])
                elif widget.label_type == 'info':
                    widget.config(bg=self.current_theme['info_bg'],
                                 fg=self.current_theme['text_primary'])
                elif widget.label_type == 'syntax':
                    widget.config(bg=self.current_theme['info_bg'],
                                 fg=self.current_theme['text_secondary'])
                elif widget.label_type == 'formula':
                    widget.config(bg=self.current_theme['input_bg'])
                    
        elif widget_class in ['Text', 'Entry']:
            widget.config(bg=self.current_theme['input_bg'],
                         fg=self.current_theme['text_primary'],
                         insertbackground=self.current_theme['text_primary'])
            
        # Recursively update children
        for child in widget.winfo_children():
            if child.winfo_class() != 'Toplevel':  # Skip toplevel windows
                self.update_theme_recursive(child)
        
    def setup_gui(self):
        # Header with theme toggle
        self.header = tk.Frame(self.root, bg=self.current_theme['header_bg'], height=80)
        self.header.pack(fill="x")
        self.header.pack_propagate(False)
        
        # Header content frame
        header_content = tk.Frame(self.header, bg=self.current_theme['header_bg'])
        header_content.pack(fill="both", expand=True)
        
        # Title (left side)
        self.title_label = tk.Label(header_content, text="🧮 Truth Table Generator", 
                                   bg=self.current_theme['header_bg'], 
                                   fg=self.current_theme['header_fg'], 
                                   font=("Segoe UI", 24, "bold"))
        self.title_label.pack(side="left", expand=True)
        
        # Theme toggle button (right side)
        theme_button_frame = tk.Frame(header_content, bg=self.current_theme['header_bg'])
        theme_button_frame.pack(side="right", padx=30, pady=20)
        
        self.theme_button = ModernButton(theme_button_frame, "🌙 Dark Theme", 
                                        self.toggle_theme, 
                                        bg_color="#6c757d", hover_color="#5a6268")
        self.theme_button.pack()
        
        # Container principale
        main_container = tk.Frame(self.root, bg=self.current_theme['bg'])
        main_container.pack(fill="both", expand=True, padx=30, pady=20)
        
        # Notebook con stile moderno
        self.notebook = ttk.Notebook(main_container, style='Modern.TNotebook')
        self.notebook.pack(fill="both", expand=True)
        
        # Tab TeX
        self.tex_frame = tk.Frame(self.notebook, bg=self.current_theme['card_bg'])
        self.tex_frame.is_card_frame = True
        self.notebook.add(self.tex_frame, text="📝 TeX Mode")
        self.setup_tex_mode()
        
        # Tab GUI
        self.gui_frame = tk.Frame(self.notebook, bg=self.current_theme['card_bg'])
        self.gui_frame.is_card_frame = True
        self.notebook.add(self.gui_frame, text="🎛️ Visual Mode")
        self.setup_gui_mode()
        
    def setup_tex_mode(self):
        # Container con padding
        container = tk.Frame(self.tex_frame, bg=self.current_theme['card_bg'])
        container.is_card_frame = True
        container.pack(fill="both", expand=True, padx=40, pady=30)
        
        # Istruzioni eleganti
        instruction_frame = tk.Frame(container, bg=self.current_theme['info_bg'], 
                                   relief="flat", bd=1)
        instruction_frame.is_info_frame = True
        instruction_frame.pack(fill="x", pady=(0, 20))
        
        info_label = tk.Label(instruction_frame, 
                             text="💡 TeX Syntax Guide", 
                             bg=self.current_theme['info_bg'], 
                             fg=self.current_theme['text_primary'], 
                             font=("Segoe UI", 14, "bold"))
        info_label.label_type = 'info'
        info_label.pack(anchor="w", padx=20, pady=(15, 5))
        
        syntax_text = ("\\neg (NOT)  •  \\land (AND)  •  \\lor, \\vee (OR)  •  \\implies (→)  •  \\iff (↔)\n"
                      "Example: (\\neg a \\lor b) \\land (a \\implies c)")
        syntax_label = tk.Label(instruction_frame, text=syntax_text, 
                               bg=self.current_theme['info_bg'], 
                               fg=self.current_theme['text_secondary'], 
                               font=("Consolas", 11), justify="left")
        syntax_label.label_type = 'syntax'
        syntax_label.pack(anchor="w", padx=20, pady=(0, 15))
        
        # Input area
        input_label = tk.Label(container, text="Enter TeX Formula:", 
                              bg=self.current_theme['card_bg'], 
                              fg=self.current_theme['text_primary'], 
                              font=("Segoe UI", 12, "bold"))
        input_label.label_type = 'primary'
        input_label.pack(anchor="w", pady=(0, 5))
        
        input_frame = tk.Frame(container, bg=self.current_theme['card_bg'])
        input_frame.is_card_frame = True
        input_frame.pack(fill="x", pady=(0, 20))
        
        self.tex_entry = tk.Text(input_frame, height=3, font=("Consolas", 12),
                                relief="solid", bd=1, padx=15, pady=10,
                                bg=self.current_theme['input_bg'], 
                                fg=self.current_theme['text_primary'],
                                selectbackground="#4A90E2",
                                insertbackground=self.current_theme['text_primary'])
        self.tex_entry.pack(side="left", fill="both", expand=True)
        
        # Pulsante generate
        button_frame = tk.Frame(container, bg=self.current_theme['card_bg'])
        button_frame.is_card_frame = True
        button_frame.pack(fill="x", pady=(0, 20))
        
        ModernButton(button_frame, "🚀 Generate Truth Table", 
                    self.process_tex_input, bg_color="#27ae60", hover_color="#229954").pack(side="right")
        
        # Tabella risultati
        self.setup_table_display(container, 'tex')
        
    def setup_gui_mode(self):
        container = tk.Frame(self.gui_frame, bg=self.current_theme['card_bg'])
        container.is_card_frame = True
        container.pack(fill="both", expand=True, padx=40, pady=30)
        
        # Input section
        input_section = tk.Frame(container, bg=self.current_theme['card_bg'])
        input_section.is_card_frame = True
        input_section.pack(fill="x", pady=(0, 20))
        
        input_label = tk.Label(input_section, text="Build Your Formula:", 
                              bg=self.current_theme['card_bg'], 
                              fg=self.current_theme['text_primary'], 
                              font=("Segoe UI", 12, "bold"))
        input_label.label_type = 'primary'
        input_label.pack(anchor="w", pady=(0, 10))
        
        # Formula display
        formula_frame = tk.Frame(input_section, bg=self.current_theme['input_bg'], 
                               relief="solid", bd=1)
        formula_frame.pack(fill="x", pady=(0, 15))
        
        self.formula_display = tk.Label(formula_frame, text="Your formula will appear here...", 
                                       bg=self.current_theme['input_bg'], 
                                       fg=self.current_theme['text_secondary'], 
                                       font=("Consolas", 14), pady=15)
        self.formula_display.label_type = 'formula'
        self.formula_display.pack(fill="x")
        
        # Pulsanti logici
        buttons_frame = tk.Frame(input_section, bg=self.current_theme['card_bg'])
        buttons_frame.is_card_frame = True
        buttons_frame.pack(fill="x", pady=(0, 15))
        
        # Row 1: Connettivi base
        row1 = tk.Frame(buttons_frame, bg=self.current_theme['card_bg'])
        row1.is_card_frame = True
        row1.pack(fill="x", pady=(0, 10))
        
        ModernButton(row1, "¬ NOT", lambda: self.add_to_formula("¬"), 
                    bg_color="#e74c3c", hover_color="#c0392b").pack(side="left", padx=(0, 10))
        ModernButton(row1, "∧ AND", lambda: self.add_to_formula(" ∧ "), 
                    bg_color="#3498db", hover_color="#2980b9").pack(side="left", padx=(0, 10))
        ModernButton(row1, "∨ OR", lambda: self.add_to_formula(" ∨ "), 
                    bg_color="#9b59b6", hover_color="#8e44ad").pack(side="left", padx=(0, 10))
        ModernButton(row1, "→ IMPLIES", lambda: self.add_to_formula(" → "), 
                    bg_color="#f39c12", hover_color="#e67e22").pack(side="left", padx=(0, 10))
        ModernButton(row1, "↔ IFF", lambda: self.add_to_formula(" ↔ "), 
                    bg_color="#1abc9c", hover_color="#16a085").pack(side="left", padx=(0, 10))
        
        # Row 2: Utility
        row2 = tk.Frame(buttons_frame, bg=self.current_theme['card_bg'])
        row2.is_card_frame = True
        row2.pack(fill="x")
        
        ModernButton(row2, "( )", lambda: self.add_to_formula("( )"), 
                    bg_color="#95a5a6", hover_color="#7f8c8d").pack(side="left", padx=(0, 10))
        ModernButton(row2, "🗑️ Clear", self.clear_formula, 
                    bg_color="#e74c3c", hover_color="#c0392b").pack(side="left", padx=(0, 10))
        ModernButton(row2, "🚀 Generate", self.process_gui_input, 
                    bg_color="#27ae60", hover_color="#229954").pack(side="right")
        
        # Input diretto
        direct_frame = tk.Frame(input_section, bg=self.current_theme['card_bg'])
        direct_frame.is_card_frame = True
        direct_frame.pack(fill="x", pady=(15, 0))
        
        direct_label = tk.Label(direct_frame, text="Or type directly:", 
                               bg=self.current_theme['card_bg'], 
                               fg=self.current_theme['text_secondary'], 
                               font=("Segoe UI", 10))
        direct_label.label_type = 'secondary'
        direct_label.pack(anchor="w")
        
        self.direct_entry = tk.Entry(direct_frame, font=("Consolas", 12), 
                                    relief="solid", bd=1, 
                                    bg=self.current_theme['input_bg'],
                                    fg=self.current_theme['text_primary'],
                                    insertbackground=self.current_theme['text_primary'])
        self.direct_entry.pack(fill="x", pady=(5, 0))
        self.direct_entry.bind('<KeyRelease>', self.update_formula_display)
        
        # Tabella risultati
        self.setup_table_display(container, 'gui')
        
    def setup_table_display(self, parent, mode_suffix):
        # Frame per la tabella
        table_frame = tk.Frame(parent, bg=self.current_theme['card_bg'])
        table_frame.is_card_frame = True
        table_frame.pack(fill="both", expand=True)
        
        # Titolo risultati
        result_label = tk.Label(table_frame, text="📊 Truth Table Results", 
                               bg=self.current_theme['card_bg'], 
                               fg=self.current_theme['text_primary'], 
                               font=("Segoe UI", 14, "bold"))
        result_label.label_type = 'primary'
        result_label.pack(anchor="w", pady=(0, 15))
        
        # Container con scrollbar
        canvas_frame = tk.Frame(table_frame, bg=self.current_theme['card_bg'])
        canvas_frame.is_card_frame = True
        canvas_frame.pack(fill="both", expand=True)
        
        # Canvas per scrolling
        canvas = tk.Canvas(canvas_frame, bg=self.current_theme['card_bg'], 
                          highlightthickness=0)
        scrollbar_v = ttk.Scrollbar(canvas_frame, orient="vertical", command=canvas.yview)
        scrollbar_h = ttk.Scrollbar(canvas_frame, orient="horizontal", command=canvas.xview)
        
        self.table_container = tk.Frame(canvas, bg=self.current_theme['card_bg'])
        self.table_container.is_card_frame = True
        
        canvas.configure(yscrollcommand=scrollbar_v.set, xscrollcommand=scrollbar_h.set)
        
        canvas.pack(side="left", fill="both", expand=True)
        scrollbar_v.pack(side="right", fill="y")
        scrollbar_h.pack(side="bottom", fill="x")
        
        canvas.create_window((0, 0), window=self.table_container, anchor="nw")
        
        # Update scroll region
        def configure_scroll_region(event):
            canvas.configure(scrollregion=canvas.bbox("all"))
        
        self.table_container.bind("<Configure>", configure_scroll_region)
        
        # Store references
        if mode_suffix == 'tex':
            self.tex_table_container = self.table_container
        else:
            self.gui_table_container = self.table_container
    
    def add_to_formula(self, symbol):
        current = self.formula_display.cget("text")
        if current == "Your formula will appear here...":
            current = ""
        
        if symbol == "( )":
            new_formula = current + "( )"
        else:
            new_formula = current + symbol
            
        self.formula_display.config(text=new_formula, fg=self.current_theme['text_primary'])
        self.direct_entry.delete(0, tk.END)
        self.direct_entry.insert(0, new_formula)
    
    def clear_formula(self):
        self.formula_display.config(text="Your formula will appear here...", 
                                   fg=self.current_theme['text_secondary'])
        self.direct_entry.delete(0, tk.END)
        
    def update_formula_display(self, event=None):
        text = self.direct_entry.get()
        if text:
            self.formula_display.config(text=text, fg=self.current_theme['text_primary'])
        else:
            self.formula_display.config(text="Your formula will appear here...", 
                                       fg=self.current_theme['text_secondary'])
    
    def create_table(self, container, headers, data):
        # Clear existing table
        for widget in container.winfo_children():
            widget.destroy()
        
        if not headers or not data:
            no_data = tk.Label(container, text="No data to display", 
                              bg=self.current_theme['card_bg'], 
                              fg=self.current_theme['text_secondary'], 
                              font=("Segoe UI", 12))
            no_data.label_type = 'secondary'
            no_data.pack(pady=50)
            return
        
        # Main table frame with border
        table_main = tk.Frame(container, bg=self.current_theme['border_color'], 
                             relief="solid", bd=1)
        table_main.pack(fill="x", pady=(0, 2))
        
        # Headers with separators
        header_frame = tk.Frame(table_main, bg=self.current_theme['table_header_bg'])
        header_frame.pack(fill="x")
        
        for i, header in enumerate(headers):
            # Header cell
            header_cell = tk.Frame(header_frame, bg=self.current_theme['table_header_bg'])
            header_cell.pack(side="left", fill="both", expand=True)
            
            header_label = tk.Label(header_cell, text=header, 
                                   bg=self.current_theme['table_header_bg'], 
                                   fg="white", 
                                   font=("Consolas", 10, "bold"), 
                                   padx=10, pady=8)
            header_label.pack(fill="both", expand=True)
            
            # Vertical separator (except for last column)
            if i < len(headers) - 1:
                separator = tk.Frame(header_frame, bg=self.current_theme['border_color'], width=1)
                separator.pack(side="left", fill="y")
        
        # Data rows with separators
        for row_num, row_data in enumerate(data):
            row_bg = (self.current_theme['table_even_row'] if row_num % 2 == 0 
                     else self.current_theme['table_odd_row'])
            
            # Row frame
            row_frame = tk.Frame(table_main, bg=row_bg)
            row_frame.pack(fill="x")
            
            for col_num, value in enumerate(row_data):
                # Cell frame
                cell_frame = tk.Frame(row_frame, bg=row_bg)
                cell_frame.pack(side="left", fill="both", expand=True)
                
                cell_text = "T" if value else "F"
                cell_color = "#27ae60" if value else "#e74c3c"
                
                cell_label = tk.Label(cell_frame, text=cell_text, 
                                     bg=row_bg, fg=cell_color,
                                     font=("Consolas", 11, "bold"), 
                                     padx=10, pady=6)
                cell_label.pack(fill="both", expand=True)
                
                # Vertical separator (except for last column)
                if col_num < len(row_data) - 1:
                    separator = tk.Frame(row_frame, bg=self.current_theme['border_color'], width=1)
                    separator.pack(side="left", fill="y")
            
            # Horizontal separator (except for last row)
            if row_num < len(data) - 1:
                h_separator = tk.Frame(table_main, bg=self.current_theme['border_color'], height=1)
                h_separator.pack(fill="x")
    
    def process_tex_input(self):
        tex_input = self.tex_entry.get("1.0", tk.END).strip()
        
        if not tex_input:
            messagebox.showwarning("Warning", "Please enter a TeX formula!")
            return
            
        try:
            unicode_expr = self.generator.parse_tex_to_unicode(tex_input)
            headers, data = self.generator.generate_truth_table_data(unicode_expr)
            self.create_table(self.tex_table_container, headers, data)
            
        except Exception as e:
            messagebox.showerror("Error", f"Error processing formula: {str(e)}")
            
    def process_gui_input(self):
        gui_input = self.direct_entry.get().strip()
        
        if not gui_input:
            messagebox.showwarning("Warning", "Please enter a formula!")
            return
            
        try:
            headers, data = self.generator.generate_truth_table_data(gui_input)
            self.create_table(self.gui_table_container, headers, data)
            
        except Exception as e:
            messagebox.showerror("Error", f"Error processing formula: {str(e)}")

def main():
    root = tk.Tk()
    app = TruthTableGUI(root)
    root.mainloop()

if __name__ == "__main__":
    main()