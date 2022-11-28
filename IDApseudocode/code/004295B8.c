int __fastcall httpd_send_usb_file_json(int *a1)
{
  if ( !nvram_match_def("usb_share_enable", "0") && !usb_acc_check(a1 + 51365) )
    return sub_428FE8(a1);
  httpd_conn_close(a1);
  return 0;
}
// 6A83E4: using guessed type int __fastcall nvram_match_def(_DWORD, _DWORD);

