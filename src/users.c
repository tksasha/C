#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct user {
  char name[32];
  int  age;
};

typedef struct user User;

void UserInspect(User *user);

User * UserNew(char name[], int age);

int main() {
  User *pu1 = UserNew("Bruce Wayne", 42);

  if(pu1) {
    UserInspect(pu1);
  }

  free(pu1);

  User *pu2 = UserNew("John McClane", 69); 

  if(pu2) {
    User u = *pu2;

    u.age = 929;

    UserInspect(&u);

    UserInspect(pu2);
  }

  free(pu2);

  User *pu3 = UserNew("Clark Kent", 59);

  if(pu3) {
    User *pu = pu3;

    pu->age = 930;

    UserInspect(pu);

    UserInspect(pu3);
  }

  free(pu3);
}

void UserInspect(User * user) {
  printf("{\n");
  printf("  name: \"%s\"\n", user->name);
  printf("  age: %d\n", user->age);
  printf("}\n");
}

User * UserNew(char name[], int age) {
  User * puser = malloc(sizeof(*puser));

  if(puser) {
    strlcpy(puser->name, name, sizeof(puser->name));

    puser->age = age;

    return puser;
  } else {
    return NULL;
  }
}
