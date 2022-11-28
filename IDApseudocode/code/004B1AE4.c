int __fastcall sub_4B1AE4(int a1)
{
  char *v2; // $v0
  int v3; // $a2
  char *v4; // $s5
  const char *v5; // $s6
  unsigned int v6; // $fp
  int v7; // $a2
  int v8; // $a2
  int v9; // $a1
  int v10; // $a0
  char *v11; // $v0
  unsigned int v12; // $v0
  char *v14; // $v0
  char v15[512]; // [sp+58h] [-528h] BYREF
  char v16[512]; // [sp+258h] [-328h] BYREF
  char v17[128]; // [sp+458h] [-128h] BYREF
  char v18[104]; // [sp+4D8h] [-A8h] BYREF
  char v19[64]; // [sp+540h] [-40h] BYREF

  memset(v15, 0, sizeof(v15));
  memset(v19, 0, sizeof(v19));
  memset(v17, 0, sizeof(v17));
  v4 = httpd_get_parm(a1, "filename");
  v2 = httpd_get_parm(a1, "sign");
  if ( v4 && (v5 = v2) != 0 )
  {
    v6 = snprintf(v16, 512, "%s%s", v4, "d1d7855dc37411e387c300163e0c16e5");
    MD5Init(v18);
    v7 = v6;
    if ( v6 >= 0x200 )
      v7 = 511;
    MD5Update(v18, v16, v7);
    MD5Final(v18);
    snprintf(
      v19,
      64,
      "%02X%02X%02X%02X%02X%02X%02X%02X%02X%02X%02X%02X%02X%02X%02X%02X",
      (unsigned __int8)v18[88],
      (unsigned __int8)v18[89],
      (unsigned __int8)v18[90],
      (unsigned __int8)v18[91],
      (unsigned __int8)v18[92],
      (unsigned __int8)v18[93],
      (unsigned __int8)v18[94],
      (unsigned __int8)v18[95],
      (unsigned __int8)v18[96],
      (unsigned __int8)v18[97],
      (unsigned __int8)v18[98],
      (unsigned __int8)v18[99],
      (unsigned __int8)v18[100],
      (unsigned __int8)v18[101],
      (unsigned __int8)v18[102],
      (unsigned __int8)v18[103]);
    if ( !strcmp(v5, v19) )
    {
      if ( check_usb_state() )
      {
        snprintf(v15, 512, "/tmp/mnt/sda1/upload/%s", v4);
        if ( !f_exists(v15) )
          return usb_upload_do_rcv(a1);
        v9 = *(unsigned __int8 *)(a1 + 210102);
        v10 = 187;
      }
      else
      {
        v9 = *(unsigned __int8 *)(a1 + 210102);
        v10 = 186;
      }
    }
    else
    {
      v9 = *(unsigned __int8 *)(a1 + 210102);
      v10 = 185;
    }
    v11 = (char *)_GET_LANG_TEXT(v10, v9, v8);
    strcpy(v17, v11);
  }
  else
  {
    v14 = (char *)_GET_LANG_TEXT(183, *(unsigned __int8 *)(a1 + 210102), v3);
    strcpy(v17, v14);
  }
  v12 = snprintf(v16, 512, "{\"success\":%s,\"message\":\"%s\"}", "false", v17);
  if ( v12 >= 0x200 )
    v12 = 511;
  return httpd_cgi_ret(a1, v16, v12, 4);
}
// 4B1D08: variable 'v8' is possibly undefined
// 4B1E3C: variable 'v3' is possibly undefined
// 6A8318: using guessed type int __fastcall _GET_LANG_TEXT(_DWORD, _DWORD, _DWORD);
// 6A8384: using guessed type int __fastcall MD5Init(_DWORD);
// 6A846C: using guessed type int __fastcall f_exists(_DWORD);
// 6A8850: using guessed type int __fastcall MD5Final(_DWORD);
// 6A88E0: using guessed type int check_usb_state(void);
// 6A8928: using guessed type int __fastcall MD5Update(_DWORD, _DWORD, _DWORD);

