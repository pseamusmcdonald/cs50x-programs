/* Aye BABBBYYY */

#include <cs50.h>

#include <stdio.h>

#include <string.h>

typedef struct {
  string name;
  int votes;
}
candidate;

/* Functions */

string winners (int highest, int num, candidate * candidates);
int highestVote (int num, candidate * candidates);


int main(int count, string running[]) {

  candidate candidates[count - 1];
  int num = 0;
  for (num = 0; num < count - 1; num++) {
    candidates[num].name = running[num + 1];
    candidates[num].votes = 0;
  }

  int votecount = get_int("Number of voters: ");

  for (int i = 0; i < votecount; i++) {

    string vcasted = get_string("Vote: ");
    int j = 0;
    bool comp = false;
    do {
      if (strcmp(vcasted, candidates[j].name) == 0) {
        candidates[j].votes += 1;
        comp = true;
        break;
      } else j++;
    }
    while ((j <= num));
    if (comp == false) printf("INVALID VOTE\n");
  }

winners(highestVote(num, candidates), num, candidates);
return 0;

}

int highestVote (int num, candidate * candidates) {
  int i = 0;
  int highest = 0;
  for (; i < num; i++) {
    int temp = candidates[i].votes;
    if (temp > highest) highest = temp;
  }
  return highest;
}

string winners (int highest, int num, candidate * candidates) {
  for (int i = 0; i < num; i++) {
    if (candidates[i].votes == highest) printf("%s\n", candidates[i].name);
  }
  return 0;
}