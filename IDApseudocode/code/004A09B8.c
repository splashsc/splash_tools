int __fastcall sub_4A09B8(int a1)
{
  char *v1; // $v0
  char *v2; // $s0
  int v3; // $s2
  char *v4; // $s1
  int i; // $s0
  int v6; // $v0
  int (__fastcall **v7)(_DWORD, _DWORD); // $t9
  const char *v8; // $a0
  int v9; // $a1
  int v10; // $v0
  char *v11; // $v0
  char *v12; // $v1
  const char *v13; // $v0
  int v14; // $t0
  int v15; // $a3
  int v16; // $a2
  int v17; // $a1
  char v19[520]; // [sp+28h] [-218h] BYREF
  int v20[4]; // [sp+230h] [-10h] BYREF

  v2 = httpd_get_parm(a1, "iface");
  v1 = httpd_get_parm(a1, "opt");
  if ( v1 && !strcmp(v1, "del") )
  {
    killall_tk("speedTest");
    nvram_set("speed_test_result", "");
  }
  else
  {
    if ( !v2 )
      v2 = "all";
    if ( !strnicmp(v2, "all", 3) )
    {
      cgi_signal_to_kernel(10, 5, 1024000);
    }
    else
    {
      v3 = split_string(v2, 44, v19, 128);
      if ( v3 > 0 )
      {
        v4 = v19;
        for ( i = 0; i != v3; ++i )
        {
          v6 = J_atoi(*(_DWORD *)v4);
          if ( v6 > 0 )
          {
            v7 = &jhl_vpnget;
            v8 = (const char *)&unk_645880;
            v9 = v6 - 101;
            if ( v6 < 101 )
            {
              v8 = "wan_name";
              v9 = v6 - 1;
              v7 = &jhl_nvget;
            }
            v10 = ((int (__fastcall *)(const char *, int, int (__fastcall **)(_DWORD, _DWORD)))v7)(v8, v9, &jhl_nvget);
            v11 = (char *)nvram_get(v10);
            if ( !v11 )
              v11 = "";
            v20[0] = (int)"speedTest";
            v20[1] = (int)v11;
            v20[2] = 0;
            eval_nowait(v20, 0, 0, 0);
          }
          v4 += 4;
        }
      }
    }
  }
  v12 = v19;
  v13 = "{\"code\":0,\"error\":\"\",\"data\":null}";
  do
  {
    v14 = *(_DWORD *)v13;
    v15 = *((_DWORD *)v13 + 1);
    v16 = *((_DWORD *)v13 + 2);
    v17 = *((_DWORD *)v13 + 3);
    v13 += 16;
    *(_DWORD *)v12 = v14;
    *((_DWORD *)v12 + 1) = v15;
    *((_DWORD *)v12 + 2) = v16;
    *((_DWORD *)v12 + 3) = v17;
    v12 += 16;
  }
  while ( v13 != "}" );
  *(_WORD *)v12 = *(_WORD *)v13;
  return httpd_cgi_ret(a1, v19, 33, 4);
}
// 6A81BC: using guessed type int __fastcall nvram_get(_DWORD);
// 6A82E4: using guessed type int __fastcall killall_tk(_DWORD);
// 6A852C: using guessed type int __fastcall eval_nowait(_DWORD, _DWORD, _DWORD, _DWORD);
// 6A8764: using guessed type int __fastcall cgi_signal_to_kernel(_DWORD, _DWORD, _DWORD);
// 6A8778: using guessed type int __fastcall split_string(_DWORD, _DWORD, _DWORD, _DWORD);
// 6A88B8: using guessed type int __fastcall strnicmp(_DWORD, _DWORD, _DWORD);
// 6A890C: using guessed type int __fastcall jhl_nvget(_DWORD, _DWORD);
// 6A8918: using guessed type int __fastcall nvram_set(_DWORD, _DWORD);
// 6A8948: using guessed type int __fastcall jhl_vpnget(_DWORD, _DWORD);
// 6A89B4: using guessed type int __fastcall J_atoi(_DWORD);

