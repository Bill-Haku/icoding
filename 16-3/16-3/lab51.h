//
//  lab51.h
//  16-3-01
//
//  Created by HakuBill on 2020/11/26.
//

#ifndef lab51_h
#define lab51_h

#define NAME_LEN 25

#define MAX_PARTS 100

struct part {
int number;
char name[NAME_LEN+1];
int on_hand;
};


int read_line(char str[], int n);
int find_part(int number, const struct part inv[], int np);
void insert(struct part inv[], int *np);
void search(const struct part inv[], int np);
void update(struct part inv[], int np);
void print(const struct part inv[], int np);


#endif /* lab51_h */
