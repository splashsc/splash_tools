int __fastcall upnp_ctrl_file_exists(int a1)
{
  _DWORD *v1; // $s1
  const char *v3; // $v0
  char *v4; // $v1
  int v5; // $t1
  int v6; // $t0
  int v7; // $a3
  int v8; // $a2
  int result; // $v0
  char v10[512]; // [sp+18h] [-200h] BYREF

  v1 = (_DWORD *)(a1 + 196608);
  if ( *(int *)(a1 + 205572) < 5 && f_exists("/var/spool/upnp.js") == 1 )
  {
    ++v1[2241];
    v1[2235] = jiffies_get() + 1000;
    v1[2237] = a1;
    v1[2236] = upnp_ctrl_file_exists;
    result = add_timer(a1 + 205540);
  }
  else
  {
    v3 = "{\"code\":0,\"error\":\"\",\"data\":null}";
    v4 = v10;
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
    result = httpd_cgi_ret(a1, v10, 33, 4);
  }
  return result;
}
// 6A838C: using guessed type int __fastcall add_timer(_DWORD);
// 6A846C: using guessed type int __fastcall f_exists(_DWORD);
// 6A8824: using guessed type int jiffies_get(void);

