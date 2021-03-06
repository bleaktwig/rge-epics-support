# 1 "../bittypes.st"
# 1 "<built-in>"
# 1 "<command-line>"
# 1 "/usr/include/stdc-predef.h" 1 3 4
# 1 "<command-line>" 2
# 1 "../bittypes.st"






program bittypesTest

%%#include "../testSupport.h"

int8_t i8;
uint8_t ui8;
int16_t i16;
uint16_t ui16;
int32_t i32;
uint32_t ui32;

assign i8 to "ushort";
assign ui8 to "ushort";
assign i16 to "ushort";
assign ui16 to "ushort";
assign i32 to "ushort";
assign ui32 to "ushort";

entry {
    seq_test_init(12);
}

ss test {
    state sizes {
        when () {
            testOk1(sizeof(i8)==1);
            testOk1(sizeof(ui8)==1);
            testOk1(sizeof(i16)==2);
            testOk1(sizeof(ui16)==2);
            testOk1(sizeof(i32)==4);
            testOk1(sizeof(ui32)==4);
        } state conversion
    }
    state conversion {
        int8_t xi8 = -1;
        uint8_t xui8 = -1;
        int16_t xi16 = -1;
        uint16_t xui16 = -1;
        int32_t xi32 = -1;
        uint32_t xui32 = -1;
        when () {
            i8 = xi8;
            pvPut(i8, SYNC);
            pvGet(i8);
            testOk1(i8==xi8);
            ui8 = xui8;
            pvPut(ui8, SYNC);
            pvGet(ui8);
            testOk1(ui8==xui8);
            i16 = xi16;
            pvPut(i16, SYNC);
            pvGet(i16);
            testOk1(i16==xi16);
            ui16 = xui16;
            pvPut(ui16, SYNC);
            pvGet(ui16);
            testOk1(ui16==xui16);
            i32 = xi32;
            pvPut(i32, SYNC);
            pvGet(i32);
            testOk1(i32!=xi32);
            ui32 = xui32;
            pvPut(ui32, SYNC);
            pvGet(ui32);
            testOk1(ui32!=xui32);
        } exit
    }
}

exit {
    seq_test_done();
}
