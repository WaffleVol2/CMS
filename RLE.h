//RLE.h by Brendan Burdett
#pragma once

int RLEncode(unsigned char* in, int iInLen, unsigned char* out, int iOutMax, unsigned char cEscape);
int RLDecode(unsigned char* in, int iInLen, unsigned char* out, int iOutMax, unsigned char cEscape);