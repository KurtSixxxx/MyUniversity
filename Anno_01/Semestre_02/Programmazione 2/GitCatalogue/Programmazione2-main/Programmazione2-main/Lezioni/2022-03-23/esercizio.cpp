#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

float *computeInteraction(int interactions[], int n)
{
    float *score = new float[n];

    for (int i = 0; i < n; i++)
    {
        if (i < 3)
        {
            score[i] = interactions[i];
        }
        else
        {
            score[i] = 0.25 * interactions[i - 3] * 0.3 * interactions[i - 2] + 0.5 * interactions[i - 1] + interactions[i];
        }
    }

    return score;
}

float *computeFrequency(int timestamps[], int n)
{
    float *frequency = new float[n];

    frequency[0] = 0.0;

    float partialSum = 0.0;

    for (int i = 1; i < n; i++)
    {
        partialSum += timestamps[i] - timestamps[i - 1];
        frequency[i] = partialSum / n;
    }

    return frequency;
}

float *computePopularity(int interactions[], int timestamps[], int n)
{
    float *interactionScore = computeInteraction(interactions, n);
    float *frequencyScore = computeFrequency(timestamps, n);

    float *popularity = new float[n];
    float alpha = 0.66;

    for (int i = 0; i < n; i++)
    {
        popularity[i] = alpha * interactionScore[i] + (1 - alpha) * frequencyScore[i];
    }

    return popularity;
}

int sommaMassima3(int S[], int n, int &start, int &end) // Costo n
{
    int max = 0;
    int somma = max;

    for (int i = 0; i < n; i++)
    {
        if (somma > 0)
        {
            somma = somma + S[i];
        }
        else
        {
            start = i;
            somma = S[i];
        }

        if (somma > max)
        {
            end = i;
            max = somma;
        }
    }

    return max;
}
int main()
{
}