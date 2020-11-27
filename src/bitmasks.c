#include <stdio.h>
#include <stdbool.h>

// 0: 000
// 1: 001 // admin
// 2: 010 // moderator
// 3: 011
// 4: 100 // newsmaker
// 5: 101
// 6: 110
// 7: 111

#define ADMIN     1
#define MODERATOR 2
#define NEWSMAKER 4

typedef struct user {
  char name[30];
  int  roles;
} User;

void inspect(User * user);

const char * b2s(bool flag);

bool is_admin(int roles);

bool is_moderator(int roles);

bool is_newsmaker(int roles);

int main() {
  User a = { "Admin", 1 };

  inspect(&a);

  User m = { "Moderator", 2 };

  inspect(&m);

  User n = { "Newsmaker", 4 };

  inspect(&n);

  User an = { "Admin and Newsmaker", 5 };

  inspect(&an);

  User mn = { "Moderator and Newsmaker", 6 };

  inspect(&mn);

  User am = { "Admin and Moderator", 3 };

  inspect(&am);

  User amn = { "Admin, Moderator and Newsmaker", 7};

  inspect(&amn);
}

void inspect(User * user) {
  printf("{\n");
  printf("       name: \"%s\",\n", user->name);
  printf("       role: %d,\n", user->roles);
  printf("      admin: %s\n", b2s(is_admin(user->roles)));
  printf("  moderator: %s\n", b2s(is_moderator(user->roles)));
  printf("  newsmaker: %s\n", b2s(is_newsmaker(user->roles)));
  printf("}\n");
}

const char * b2s(bool flag) {
  return flag ? "true" : "false";
}

bool is_admin(int roles) {
  return (roles & ADMIN) > 0 ? true : false;
}

bool is_moderator(int roles) {
  return (roles & MODERATOR) > 0 ? true : false;
}

bool is_newsmaker(int roles) {
  return (roles & NEWSMAKER) > 0 ? true : false;
}
