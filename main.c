#include <conio.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

void print_menu(void);
void clear_screen(void);
void pause_screen(void);
void clear_input(void);
void check_balance(double balance);
double prompt_amount(const char* action);

int main(void) {
  int choice = 0;
  double balance = 0.0;
  double amount = 0.0;

  while (true) {
    clear_screen();

    printf("=== BANKING PROGRAM ===\n\n");
    print_menu();

    printf("Enter your choice: ");

    if (scanf_s("%d", &choice) != 1) {
      clear_input();
      printf("\nInvalid input.\n");
      pause_screen();
      continue;
    }

    clear_input();
    clear_screen();

    if (choice == 1) {
      check_balance(balance);
      pause_screen();

    } else if (choice == 2) {
      amount = prompt_amount("deposit");

      balance += amount;

      printf("\nSuccessfully deposited %.2f\n", amount);
      printf("New balance: %.2f\n", balance);

      pause_screen();

    } else if (choice == 3) {
      amount = prompt_amount("withdraw");

      if (amount > balance) {
        printf("\nYou don't have enough money.\n");
        printf("Current balance: %.2f\n", balance);
      } else {
        balance -= amount;

        printf("\nSuccessfully withdrew %.2f\n", amount);
        printf("New balance: €%.2f\n", balance);
      }

      pause_screen();

    } else if (choice == 4) {
      printf("Exitting...\n");
      break;

    } else {
      printf("Invalid option.\n");
      pause_screen();
    }
  }

  return 0;
}

void print_menu(void) {
  printf("Select an option:\n");
  printf("1. Check balance\n");
  printf("2. Deposit money\n");
  printf("3. Withdraw money\n");
  printf("4. Exit\n\n");
}

void clear_screen(void) {
  system("cls");
}

void pause_screen(void) {
  printf("\nPress any key to return to the menu...");
  _getch();
}

void clear_input(void) {
  int c = 0;

  while ((c = getchar()) != '\n' && c != EOF) {}
}

void check_balance(double balance) {
  printf("Your current balance is €%.2f\n", balance);
}

double prompt_amount(const char* action) {
  double amount = 0.0;

  do {
    printf("Enter an amount to %s: ", action);

    if (scanf_s("%lf", &amount) != 1) {
      clear_input();
      printf("Invalid amount.\n");
      amount = 0.0;
      continue;
    }

    clear_input();

    if (amount <= 0) {
      printf("Amount must be greater than 0.\n");
    }

  } while (amount <= 0);

  return amount;
}
