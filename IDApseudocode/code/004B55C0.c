int usb_send_email()
{
  char *v0; // $v0

  if ( nvram_match_def("usb_send_email_en", "0") )
    return -1;
  v0 = (char *)nvram_get("proxy_http_port");
  if ( !v0 )
    v0 = "0";
  if ( !J_atoi(v0) || nvram_match_def("proxy_http_status", "0") || nvram_match_def("usb_share_enable", "0") )
    return -1;
  system("proxy_usb_send_email &");
  return 0;
}
// 6A81BC: using guessed type int __fastcall nvram_get(_DWORD);
// 6A83E4: using guessed type int __fastcall nvram_match_def(_DWORD, _DWORD);
// 6A89B4: using guessed type int __fastcall J_atoi(_DWORD);

