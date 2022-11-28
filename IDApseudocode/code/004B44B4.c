int __fastcall sub_4B44B4(int a1)
{
  int v2; // $a2
  char *v3; // $v0
  char *v4; // $v0
  int v5; // $a2
  char *v6; // $s5
  const char *v7; // $s7
  unsigned int v8; // $fp
  int v9; // $a2
  int v10; // $a1
  int v11; // $a0
  char *v12; // $v0
  const char *v13; // $a3
  unsigned int v14; // $v0
  char *v16; // $v0
  char v17[512]; // [sp+58h] [-5A8h] BYREF
  char v18[512]; // [sp+258h] [-3A8h] BYREF
  char v19[256]; // [sp+458h] [-1A8h] BYREF
  char v20[104]; // [sp+558h] [-A8h] BYREF
  char v21[64]; // [sp+5C0h] [-40h] BYREF

  memset(v17, 0, sizeof(v17));
  memset(v21, 0, sizeof(v21));
  v3 = (char *)_GET_LANG_TEXT(188, *(unsigned __int8 *)(a1 + 210102), v2);
  strcpy(v19, v3);
  v6 = httpd_get_parm(a1, "filename");
  v4 = httpd_get_parm(a1, "sign");
  if ( !v6 )
  {
    v10 = *(unsigned __int8 *)(a1 + 210102);
    v11 = 183;
    goto LABEL_7;
  }
  v7 = v4;
  if ( !v4 )
  {
    v10 = *(unsigned __int8 *)(a1 + 210102);
    v11 = 184;
    goto LABEL_7;
  }
  v8 = snprintf(v18, 512, "%s%s", v6, "d1d7855dc37411e387c300163e0c16e5");
  MD5Init(v20);
  v9 = v8;
  if ( v8 >= 0x200 )
    v9 = 511;
  MD5Update(v20, v18, v9);
  MD5Final(v20);
  snprintf(
    v21,
    64,
    "%02X%02X%02X%02X%02X%02X%02X%02X%02X%02X%02X%02X%02X%02X%02X%02X",
    (unsigned __int8)v20[88],
    (unsigned __int8)v20[89],
    (unsigned __int8)v20[90],
    (unsigned __int8)v20[91],
    (unsigned __int8)v20[92],
    (unsigned __int8)v20[93],
    (unsigned __int8)v20[94],
    (unsigned __int8)v20[95],
    (unsigned __int8)v20[96],
    (unsigned __int8)v20[97],
    (unsigned __int8)v20[98],
    (unsigned __int8)v20[99],
    (unsigned __int8)v20[100],
    (unsigned __int8)v20[101],
    (unsigned __int8)v20[102],
    (unsigned __int8)v20[103]);
  if ( strcmp(v7, v21) )
  {
    v10 = *(unsigned __int8 *)(a1 + 210102);
    v11 = 185;
LABEL_7:
    v12 = (char *)_GET_LANG_TEXT(v11, v10, v5);
    strcpy(v19, v12);
    v13 = "false";
    goto LABEL_8;
  }
  snprintf(v17, 512, "/tmp/mnt/sda1/upload/%s", v6);
  if ( !f_exists64(v17) )
  {
    v10 = *(unsigned __int8 *)(a1 + 210102);
    v11 = 143;
    goto LABEL_7;
  }
  unlink(v17);
  if ( f_exists64(v17) )
  {
    v10 = *(unsigned __int8 *)(a1 + 210102);
    v11 = 113;
    goto LABEL_7;
  }
  v16 = (char *)_GET_LANG_TEXT(188, *(unsigned __int8 *)(a1 + 210102), v5);
  strcpy(v19, v16);
  v13 = "true";
LABEL_8:
  v14 = snprintf(v18, 512, "{\"success\":%s,\"message\":\"%s\"}", v13, v19);
  if ( v14 >= 0x200 )
    v14 = 511;
  return httpd_cgi_ret(a1, v18, v14, 4);
}
// 4B4540: variable 'v2' is possibly undefined
// 4B46F8: variable 'v5' is possibly undefined
// 6A8318: using guessed type int __fastcall _GET_LANG_TEXT(_DWORD, _DWORD, _DWORD);
// 6A8384: using guessed type int __fastcall MD5Init(_DWORD);
// 6A8850: using guessed type int __fastcall MD5Final(_DWORD);
// 6A8928: using guessed type int __fastcall MD5Update(_DWORD, _DWORD, _DWORD);

