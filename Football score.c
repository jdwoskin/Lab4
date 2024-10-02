// Function to find all combinations
void findCombinations(int score, int td, int fg, int safety, int td2, int td1) {
    if (score == 0) {
        printf("TD: %d, FG: %d, Safety: %d, TD+2: %d, TD+1: %d\n", td, fg, safety, td2, td1);
        return;
    }
    //subtract points and call function again with updated count
    if (score >= 8) findCombinations(score - 8, td, fg, safety, td2 + 1, td1);
    if (score >= 7) findCombinations(score - 7, td, fg, safety, td2, td1 + 1);
    if (score >= 6) findCombinations(score - 6, td + 1, fg, safety, td2, td1);
    if (score >= 3) findCombinations(score - 3, td, fg + 1, safety, td2, td1);
    if (score >= 2) findCombinations(score - 2, td, fg, safety + 1, td2, td1);
}

int main() {
    int score;
    while (1) {
        // Prompt user to enter score
        printf("Enter the NFL score (<= 1 to quit): ");
        scanf("%d", &score);
        // If input is less than or equal to 1 exit
        if (score <= 1) break;
        // Print all possible combinations
        printf("Possible combinations for score %d:\n", score);
        findCombinations(score, 0, 0, 0, 0, 0);
    }
    return 0;
}
