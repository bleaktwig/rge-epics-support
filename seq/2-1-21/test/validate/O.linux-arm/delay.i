# 1 "../delay.st"
# 1 "<built-in>"
# 1 "<command-line>"
# 1 "/usr/include/stdc-predef.h" 1 3 4
# 1 "<command-line>" 2
# 1 "../delay.st"




program delayTest



option +s;

%%#include "errlog.h"

float v = 0;
assign v;

ss test {
    float thr = 5.0;
    float hyst = 0.45;
    state low {
        entry {
            errlogPrintf("state low: v = %g\n",v);
            errlogPrintf("state low: thr = %g, hyst = %g\n",thr,hyst);
        }
        when (v >= thr+hyst) {
            errlogPrintf("low, v = %g, transition to high\n",v);
        } state high
    }
    state high {
        entry {
            errlogPrintf("state high: v = %g\n",v);
            errlogPrintf("state high: thr = %g, hyst = %g\n",thr,hyst);
        }
        when (v <= thr-hyst) {
            errlogPrintf("high, v = %g, transition to low\n",v);
        } state low
    }
}

ss ramp {
    float lo = 4.0;
    float hi = 6.0;
    float step = 0.1;
    float dt = 0.1;
    float t = 0.0;
    state up {
        when (v >= hi) {
            v = hi;
            errlogPrintf("go down, v = %g, t = %g\n",v,t);
            pvPut(v);
        } state down
        when (delay(dt)) {
            t += dt;
            v += step;
            errlogPrintf("up, v = %g, t = %g\n",v,t);
            pvPut(v);
        } state up
    }
    state down {
        when (v <= lo) {
            v = lo;
            errlogPrintf("go up, v = %g, t = %g\n",v,t);
            pvPut(v);
        } state up
        when (delay(dt)) {
            v -= step;
            t += dt;
            errlogPrintf("down, v = %g, t = %g\n",v,t);
            pvPut(v);
        } state down
    }
}
