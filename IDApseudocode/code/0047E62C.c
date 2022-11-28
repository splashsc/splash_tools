int __fastcall sub_47E62C(int a1)
{
  const char *v2; // $v0
  char *v3; // $s0
  int v4; // $v0
  char *v5; // $a1
  signed int v7; // $v0
  int (__fastcall *v8)(int, const char *, char *, signed int); // $t9
  char *v9; // $v0

  v2 = (const char *)nvram_get("userinfo_htm");
  if ( v2 )
  {
    v3 = (char *)v2;
    if ( !strcmp(v2, (const char *)&off_4CFA50) )
    {
      _mem_malloc(0x200000, "userinfo_htm", 5439);
      v3 = v9;
      if ( v9 )
      {
        v7 = read_tg_html_from_usb(v9, 0x200000, "userinfofile");
        if ( v7 >= 4 )
        {
          v8 = (int (__fastcall *)(int, const char *, char *, signed int))httpd_send_mime_file;
          return v8(a1, "text/html", v3, v7);
        }
        _mem_free(v3);
      }
    }
    else if ( *v3 )
    {
      v7 = strlen(v3);
      if ( (unsigned int)v7 >= 4 )
      {
        v8 = httpd_send_html_file;
        return v8(a1, "text/html", v3, v7);
      }
    }
  }
  v4 = get_web_language_type(a1);
  if ( v4 == 1 )
  {
    v5 = "/userinfo_gg_org_en.htm";
    return httpd_cgi_ret(a1, v5, 0, 2);
  }
  if ( v4 != 99 )
  {
    v5 = "/userinfo_gg_org.htm";
    return httpd_cgi_ret(a1, v5, 0, 2);
  }
  return httpd_cgi_ret(a1, "/userinfo_gg_org_ft.htm", 0, 2);
}
// 47E764: variable 'v9' is possibly undefined
// 4CFA50: using guessed type void *off_4CFA50;
// 6A81BC: using guessed type int __fastcall nvram_get(_DWORD);
// 6A8974: using guessed type int __fastcall read_tg_html_from_usb(_DWORD, _DWORD, _DWORD);

