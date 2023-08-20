#ifndef  ERL_COMM_H
#define ERL_COMM_H

typedef unsigned char byte;

int write_cmd(byte *buf, int len);
int read_cmd(byte *buf);

#endif // ! ERL_COMM_H
