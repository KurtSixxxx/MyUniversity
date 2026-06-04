          ;       Sommare i numeri 2,3,4,1 e salvare in memoria il risultato

          ;DICHIARO LE VARIABILI
NUM1      DCD     2
NUM2      DCD     3
NUM3      DCD     4
NUM4      DCD     1
RISULTATO FILL    4

          ;CARICO LE VARIABILI NEI REGISTRI
          MOV     R1, #NUM1
          LDR     R1, [R1]
          MOV     R2, #NUM2
          LDR     R2, [R2]
          MOV     R3, #NUM3
          LDR     R3, [R3]
          MOV     R4, #NUM4
          LDR     R4, [R4]

          ;SOMMO  LE VARIABLI
          ADD     R5, R1, R2
          ADD     R5, R5, R3
          ADD     R5, R5, R4
          MOV     R6, #RISULTATO


          STR     R5, [R6]