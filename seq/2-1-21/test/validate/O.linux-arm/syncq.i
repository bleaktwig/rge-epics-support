# 1 "../syncq.st"
# 1 "<built-in>"
# 1 "<command-line>"
# 1 "/usr/include/stdc-predef.h" 1 3 4
# 1 "<command-line>" 2
# 1 "../syncq.st"






program syncqTest

option +s;

string s[3];
assign s to "syncq";
monitor s;

string s1[1];
assign s1 to "syncq";
monitor s1;
syncq s1 5;

int n = 0;
assign n;
monitor n;

ss get {
    state get {
        when (pvGetQ(s)) {
            printf("got: [%s,%s,%s]\n", s[0], s[1], s[2]);
        } state pause
    }
    state pause {
        when (delay(2)) {
        } state get
    }
}

ss get1 {
    state get {
        when (pvGetQ(s1)) {
            printf("got: [%s]\n", s1[0]);
        } state pause
    }
    state pause {
        when (delay(2)) {
        } state get
    }
}

ss put {
    state put {
        when (delay(1)) {
            sprintf(s[0], "%d", n);
            sprintf(s[1], "%d", -n);
            sprintf(s[2], "%d", 2*n);
            pvPut(s);
            n++;
            pvPut(n);
        } state put
    }
}

ss flush {
    state idle {
        when (n%20==0) {
            printf("flush\n");
            pvFlushQ(s);
            pvFlushQ(s1);
        } state flush
    }
    state flush {
        when (n%20!=0) {
        } state idle
    }
}
