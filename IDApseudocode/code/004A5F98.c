int __fastcall sub_4A5F98(int a1)
{
  const char *v2; // $v0
  const char *v3; // $v0
  char *v4; // $v1
  int v5; // $t1
  int v6; // $t0
  int v7; // $a3
  int v8; // $a2
  int result; // $v0
  char *v10; // $s1
  char *v11; // $v0
  char v12[512]; // [sp+18h] [-30Ch] BYREF
  char v13[256]; // [sp+218h] [-10Ch] BYREF
  int v14; // [sp+318h] [-Ch]

  v2 = (const char *)nvram_get("upnp_enable");
  if ( v2
    && !strcmp(v2, "1")
    && (v10 = httpd_get_parm(a1, "remove_ext_proto")) != 0
    && *v10
    && (v11 = httpd_get_parm(a1, "remove_ext_port")) != 0
    && *v11
    && (sprintf(v13, "%s %s\n", v10, v11), f_write_string("/var/spool/upnp.delete", v13, 0, 0), !killall("upnp", 17)) )
  {
    v14 = 0;
    *(_DWORD *)(a1 + 205572) = 0;
    upnp_ctrl_file_exists(a1);
    result = v14;
  }
  else
  {
    v3 = "{\"code\":0,\"error\":\"\",\"data\":null}";
    v4 = v12;
    do
    {
      v5 = *(_DWORD *)v3;
      v6 = *((_DWORD *)v3 + 1);
      v7 = *((_DWORD *)v3 + 2);
      v8 = *((_DWORD *)v3 + 3);
      v3 += 16;
      *(_DWORD *)v4 = v5;
      *((_DWORD *)v4 + 1) = v6;
      *((_DWORD *)v4 + 2) = v7;
      *((_DWORD *)v4 + 3) = v8;
      v4 += 16;
    }
    while ( v3 != "}" );
    *(_WORD *)v4 = *(_WORD *)v3;
    result = httpd_cgi_ret(a1, v12, 33, 4);
  }
  return result;
}
// 6A8178: using guessed type int __fastcall killall(_DWORD, _DWORD);
// 6A81BC: using guessed type int __fastcall nvram_get(_DWORD);
// 6A8940: using guessed type int __fastcall f_write_string(_DWORD, _DWORD, _DWORD, _DWORD);

