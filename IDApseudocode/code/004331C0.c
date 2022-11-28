int __fastcall sub_4331C0(int a1, char *a2)
{
  unsigned int v4; // $v0
  unsigned int v6[22]; // [sp+50h] [-90h] BYREF
  unsigned __int8 v7; // [sp+A8h] [-38h]
  unsigned __int8 v8; // [sp+A9h] [-37h]
  unsigned __int8 v9; // [sp+AAh] [-36h]
  unsigned __int8 v10; // [sp+ABh] [-35h]
  unsigned __int8 v11; // [sp+ACh] [-34h]
  unsigned __int8 v12; // [sp+ADh] [-33h]
  unsigned __int8 v13; // [sp+AEh] [-32h]
  unsigned __int8 v14; // [sp+AFh] [-31h]
  unsigned __int8 v15; // [sp+B0h] [-30h]
  unsigned __int8 v16; // [sp+B1h] [-2Fh]
  unsigned __int8 v17; // [sp+B2h] [-2Eh]
  unsigned __int8 v18; // [sp+B3h] [-2Dh]
  unsigned __int8 v19; // [sp+B4h] [-2Ch]
  unsigned __int8 v20; // [sp+B5h] [-2Bh]
  unsigned __int8 v21; // [sp+B6h] [-2Ah]
  unsigned __int8 v22; // [sp+B7h] [-29h]
  int v23[8]; // [sp+B8h] [-28h] BYREF
  int v24; // [sp+D8h] [-8h] BYREF

  v23[0] = 0;
  v23[1] = 0;
  v23[2] = 0;
  v23[3] = 0;
  v23[4] = 0;
  v23[5] = 0;
  v23[6] = 0;
  v23[7] = 0;
  v24 = jiffies_get();
  IpToStr(v23, a1);
  FBR_MD5Init(v6);
  v4 = strlen((const char *)v23);
  FBR_MD5Update(v6, (int)v23, v4);
  FBR_MD5Update(v6, (int)&v24, 4u);
  FBR_MD5Final(v6);
  return sprintf(
           a2,
           "%02X%02X%02X%02X%02X%02X%02X%02X%02X%02X%02X%02X%02X%02X%02X%02X",
           v7,
           v10,
           v9,
           v8,
           v11,
           v14,
           v13,
           v12,
           v17,
           v16,
           v15,
           v18,
           v22,
           v20,
           v21,
           v19);
}
// 6A8644: using guessed type int __fastcall IpToStr(_DWORD, _DWORD);
// 6A8824: using guessed type int jiffies_get(void);

