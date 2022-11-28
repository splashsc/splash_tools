int __fastcall sub_4AFC68(int a1)
{
  char *v2; // $v0
  char *v3; // $s1
  const char *v4; // $s0
  const char *v5; // $v0
  char *v6; // $v1
  int v7; // $t1
  int v8; // $t0
  int v9; // $a3
  int v10; // $a2
  int v12; // $a0
  char v13[1028]; // [sp+20h] [-404h] BYREF

  v3 = httpd_get_parm(a1, "printer_enable");
  v2 = httpd_get_parm(a1, "printer_port");
  if ( v2 && (v4 = v2, !nvram_match_def(&unk_64DE5C, v2)) )
  {
    if ( !J_atoi(v4) )
      v4 = "9100";
    nvram_set(&unk_64DE5C, v4);
    if ( !v3 || nvram_match_def("usb_printer_en", v3) )
      goto LABEL_13;
  }
  else if ( !v3 || nvram_match_def("usb_printer_en", v3) )
  {
    goto LABEL_5;
  }
  nvram_set("usb_printer_en", v3);
LABEL_13:
  killall_tk("p910nd");
  if ( nvram_match_def("usb_printer_en", "1") )
  {
    jhl_nv_get_def(&unk_64DE5C);
    xstart("p910nd", "-f");
  }
  jhl_parm_commit(v12);
LABEL_5:
  v5 = "{\"code\":0,\"error\":\"\",\"data\":null}";
  v6 = v13;
  do
  {
    v7 = *(_DWORD *)v5;
    v8 = *((_DWORD *)v5 + 1);
    v9 = *((_DWORD *)v5 + 2);
    v10 = *((_DWORD *)v5 + 3);
    v5 += 16;
    *(_DWORD *)v6 = v7;
    *((_DWORD *)v6 + 1) = v8;
    *((_DWORD *)v6 + 2) = v9;
    *((_DWORD *)v6 + 3) = v10;
    v6 += 16;
  }
  while ( v5 != "}" );
  *(_WORD *)v6 = *(_WORD *)v5;
  return httpd_cgi_ret(a1, v13, 33, 4);
}
// 4AFE50: variable 'v12' is possibly undefined
// 6A8180: using guessed type int __fastcall jhl_parm_commit(_DWORD);
// 6A82E4: using guessed type int __fastcall killall_tk(_DWORD);
// 6A83E4: using guessed type int __fastcall nvram_match_def(_DWORD, _DWORD);
// 6A84C8: using guessed type int __fastcall jhl_nv_get_def(_DWORD);
// 6A85AC: using guessed type int __fastcall xstart(_DWORD, _DWORD);
// 6A8918: using guessed type int __fastcall nvram_set(_DWORD, _DWORD);
// 6A89B4: using guessed type int __fastcall J_atoi(_DWORD);

