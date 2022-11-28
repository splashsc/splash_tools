int __fastcall sub_4B48CC(int a1)
{
  char *v2; // $s4
  int v3; // $a2
  char *v4; // $s1
  char *v5; // $v0
  int v6; // $a1
  int v7; // $a0
  char *v8; // $v0
  unsigned int v9; // $v0
  char v11[1024]; // [sp+20h] [-680h] BYREF
  char v12[512]; // [sp+420h] [-280h] BYREF
  char v13[128]; // [sp+620h] [-80h] BYREF

  memset(v12, 0, sizeof(v12));
  memset(v13, 0, sizeof(v13));
  v2 = httpd_get_parm(a1, "filename");
  v4 = httpd_get_parm(a1, "path");
  usb_httpd_conn_check_user(a1);
  if ( *(_BYTE *)(a1 + 43) != 1 )
  {
    v6 = *(unsigned __int8 *)(a1 + 210102);
    v7 = 2;
    goto LABEL_11;
  }
  if ( v4 )
  {
    v5 = strstr(v4, "/usb/");
    v4 = v5 + 5;
    if ( v5 )
    {
      if ( v5 != (char *)-5 )
      {
        if ( check_usb_state() )
          goto LABEL_6;
LABEL_16:
        v6 = *(unsigned __int8 *)(a1 + 210102);
        v7 = 186;
        goto LABEL_11;
      }
    }
  }
  v4 = "";
  if ( !check_usb_state() )
    goto LABEL_16;
LABEL_6:
  if ( v2 )
  {
    snprintf(v12, 512, "/tmp/mnt/sda1/%s/%s", v4, v2);
    if ( f_exists64(v12) )
    {
      unlink(v12);
      if ( f_exists64(v12) )
      {
        v6 = *(unsigned __int8 *)(a1 + 210102);
        v7 = 113;
      }
      else
      {
        v6 = *(unsigned __int8 *)(a1 + 210102);
        v7 = 188;
      }
    }
    else
    {
      v6 = *(unsigned __int8 *)(a1 + 210102);
      v7 = 143;
    }
  }
  else
  {
    v6 = *(unsigned __int8 *)(a1 + 210102);
    v7 = 183;
  }
LABEL_11:
  v8 = (char *)_GET_LANG_TEXT(v7, v6, v3);
  strcpy(v13, v8);
  sync();
  v9 = snprintf(
         v11,
         1024,
         "<html><head><script type='text/javascript'>function init(){alert('%s');window.parent.location.href='/usb/%s';}<"
         "/script><body onLoad='init();'></body></head></html>",
         v13,
         v4);
  if ( v9 >= 0x400 )
    v9 = 1023;
  return httpd_cgi_ret(a1, v11, v9, 4);
}
// 4B4A80: variable 'v3' is possibly undefined
// 6A8318: using guessed type int __fastcall _GET_LANG_TEXT(_DWORD, _DWORD, _DWORD);
// 6A88E0: using guessed type int check_usb_state(void);

