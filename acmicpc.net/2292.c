//2017-07-25 22:38:42
#include <stdio.h>
int main() { int add = 0, now = 1, count = 1, tar; scanf("%d", &tar); while (tar > now + add) { now += add; add += 6; ++count; }printf("%d", count); }