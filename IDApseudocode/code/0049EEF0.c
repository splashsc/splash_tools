int __fastcall pppoe_bridge_md5(char *a1, int a2, int a3)
{
  char v5[104]; // [sp+50h] [-74h] BYREF
  int v6; // [sp+B8h] [-Ch]
  int v7; // [sp+BCh] [-8h]

  v7 = a2;
  v6 = a3;
  MD5Init(v5);
  MD5Update(v5, v7, v6);
  MD5Final(v5);
  return sprintf(
           a1,
           "%02x%02x%02x%02x%02x%02x%02x%02x%02x%02x%02x%02x%02x%02x%02x%02x",
           (unsigned __int8)v5[88],
           (unsigned __int8)v5[89],
           (unsigned __int8)v5[90],
           (unsigned __int8)v5[91],
           (unsigned __int8)v5[92],
           (unsigned __int8)v5[93],
           (unsigned __int8)v5[94],
           (unsigned __int8)v5[95],
           (unsigned __int8)v5[96],
           (unsigned __int8)v5[97],
           (unsigned __int8)v5[98],
           (unsigned __int8)v5[99],
           (unsigned __int8)v5[100],
           (unsigned __int8)v5[101],
           (unsigned __int8)v5[102],
           (unsigned __int8)v5[103]);
}
// 6A8384: using guessed type int __fastcall MD5Init(_DWORD);
// 6A8850: using guessed type int __fastcall MD5Final(_DWORD);
// 6A8928: using guessed type int __fastcall MD5Update(_DWORD, _DWORD, _DWORD);

