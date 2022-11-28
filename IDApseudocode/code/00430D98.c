int __fastcall httpd_passwd_md5(char *a1, const char *a2)
{
  const char *v4; // $v0
  int v5; // $s2
  char v7[512]; // [sp+50h] [-26Ch] BYREF
  unsigned int v8[22]; // [sp+250h] [-6Ch] BYREF
  char v9[20]; // [sp+2A8h] [-14h] BYREF

  memset(v7, 0, sizeof(v7));
  v4 = (const char *)get_sn();
  v5 = snprintf(v7, 512, "%s%s%sjhttpd", "fja285dri9&cii386&$", a2, v4);
  FBR_MD5Init(v8);
  FBR_MD5Update(v8, (int)v7, v5);
  FBR_MD5Final(v8);
  if ( !dword_67D2EC )
  {
    dword_67D2EC = 1;
    byte_66B592 = 68;
    byte_66B597 = 50;
    byte_66B59D = 73;
    aes_set_key(&unk_67D2F0, &unk_66B590, 16);
  }
  aes_aes(&unk_67D2F0, v9, v5, v7, 0);
  return sprintf(
           a1,
           "%02X%02X%02X%02X%02X%02X%02X%02X%02X%02X%02X%02X%02X%02X%02X%02X",
           (unsigned __int8)v7[0],
           (unsigned __int8)v7[3],
           (unsigned __int8)v7[2],
           (unsigned __int8)v7[1],
           (unsigned __int8)v7[4],
           (unsigned __int8)v7[7],
           (unsigned __int8)v7[6],
           (unsigned __int8)v7[5],
           (unsigned __int8)v7[10],
           (unsigned __int8)v7[9],
           (unsigned __int8)v7[8],
           (unsigned __int8)v7[11],
           (unsigned __int8)v7[15],
           (unsigned __int8)v7[13],
           (unsigned __int8)v7[14],
           (unsigned __int8)v7[12]);
}
// 66B592: using guessed type char byte_66B592;
// 66B597: using guessed type char byte_66B597;
// 66B59D: using guessed type char byte_66B59D;
// 67D2EC: using guessed type int dword_67D2EC;
// 6A81D8: using guessed type int get_sn(void);
// 6A8464: using guessed type int __fastcall aes_aes(_DWORD, _DWORD, _DWORD, _DWORD, _DWORD);
// 6A8854: using guessed type int __fastcall aes_set_key(_DWORD, _DWORD, _DWORD);

