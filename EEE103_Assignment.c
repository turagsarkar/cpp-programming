#include <stdio.h>

int main(void) {
    int categoryChoice, connectionChoice;
    double totalUnits, activeHours, peakHours;

    printf("=== User Activity Performance Evaluation ===\n\n");

    printf("Select User Category:\n");
    printf("  1. Residential\n");
    printf("  2. Commercial\n");
    printf("  3. Industrial\n");
    printf("Enter choice (1-3): ");
    scanf("%d", &categoryChoice);

    printf("Enter Total Resource Usage Units: ");
    scanf("%lf", &totalUnits);

    printf("Enter Active Usage Duration (hours per day): ");
    scanf("%lf", &activeHours);

    printf("Enter Peak Usage Duration (hours per day): ");
    scanf("%lf", &peakHours);

    printf("Select Connection Type:\n");
    printf("  1. Standard\n");
    printf("  2. Advanced\n");
    printf("Enter choice (1-2): ");
    scanf("%d", &connectionChoice);

    if (activeHours <= 0) {
        printf("\nError: Active Usage Hours must be greater than 0.\n");
        return 1;
    }
    if (categoryChoice < 1 || categoryChoice > 3) {
        printf("\nError: Invalid user category.\n");
        return 1;
    }
    if (connectionChoice < 1 || connectionChoice > 2) {
        printf("\nError: Invalid connection type.\n");
        return 1;
    }

    double aur = totalUnits / activeHours;
    double pur = peakHours / activeHours;
    double usi = aur * pur;

    char categoryName[20];
    if (categoryChoice == 1) {
        sprintf(categoryName, "Residential");
    } else if (categoryChoice == 2) {
        sprintf(categoryName, "Commercial");
    } else {
        sprintf(categoryName, "Industrial");
    }

    char connectionName[10];
    if (connectionChoice == 1) {
        sprintf(connectionName, "Standard");
    } else {
        sprintf(connectionName, "Advanced");
    }

    char evaluation[20];
    int isOptimalCandidate = 0;

    if (categoryChoice == 1) {
        if (usi < 5) {
            sprintf(evaluation, "Efficient");
            isOptimalCandidate = 1;
        } else if (usi <= 10) {
            sprintf(evaluation, "Moderate");
        } else {
            sprintf(evaluation, "Overuse");
        }
    } else if (categoryChoice == 2) {
        if (usi < 8) {
            sprintf(evaluation, "Balanced");
            isOptimalCandidate = 1;
        } else if (usi <= 15) {
            sprintf(evaluation, "High Load");
        } else {
            sprintf(evaluation, "Critical");
        }
    } else {
        if (usi < 12) {
            sprintf(evaluation, "Normal Operation");
            isOptimalCandidate = 1;
        } else if (usi <= 20) {
            sprintf(evaluation, "Warning Level");
        } else {
            sprintf(evaluation, "Severe Stress");
        }
    }

    printf("\n=== Results ===\n");
    printf("User Category          : %s\n", categoryName);
    printf("Connection Type        : %s\n", connectionName);
    printf("Total Usage Units      : %.2lf\n", totalUnits);
    printf("Active Usage Hours     : %.2lf\n", activeHours);
    printf("Peak Usage Hours       : %.2lf\n", peakHours);
    printf("Average Usage Rate AUR : %.2lf\n", aur);
    printf("Peak Utilization PUR   : %.2lf\n", pur);
    printf("Usage Stress Index USI : %.2lf\n", usi);
    printf("Evaluation Result      : %s\n", evaluation);

    if (connectionChoice == 2 && isOptimalCandidate) {
        printf("Note                   : Optimized System\n");
    }
    if (peakHours > 0.5 * activeHours) {
        printf("Note                   : Peak-Heavy Usage Detected\n");
    }

    return 0;
}
