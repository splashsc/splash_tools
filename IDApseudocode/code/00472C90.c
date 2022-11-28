int __fastcall sub_472C90(int a1)
{
  const char *v2; // $v0
  signed int v3; // $v0
  char *v4; // $s0

  v2 = (const char *)nvram_get("wx_wifi_jump_html");
  if ( !v2 )
    return httpd_send_html_file(a1, "text/html", "", 0);
  v4 = (char *)v2;
  v3 = strlen(v2);
  return httpd_send_html_file(a1, "text/html", v4, v3);
}
// 6A81BC: using guessed type int __fastcall nvram_get(_DWORD);

