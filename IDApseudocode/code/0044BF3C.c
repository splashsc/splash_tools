int __fastcall ai_cgi_common_timeout(_DWORD *a1)
{
  _DWORD *v1; // $s0
  int v2; // $v0
  int v4; // $v0
  int result; // $v0
  const char *v6; // $v0
  char *v7; // $v1
  int v8; // $t1
  int v9; // $t0
  int v10; // $a3
  int v11; // $a2
  char v12[1024]; // [sp+18h] [-400h] BYREF

  v1 = a1 + 49152;
  v2 = a1[51393];
  if ( v2 < 5 && (v4 = v2 + 1, a1[52524]) )
  {
    a1[51393] = v4;
    a1[51387] = jiffies_get() + 1000;
    v1[2237] = a1;
    v1[2236] = ai_cgi_common_timeout;
    result = add_timer(a1 + 51385);
  }
  else
  {
    a1[51388] = httpd_keep_alive_timeout;
    a1[51387] = jiffies_get() + 5000;
    add_timer(a1 + 51385);
    result = a1[52524];
    if ( result )
    {
      v6 = "{\"code\":0,\"error\":\"\",\"data\":null}";
      a1[52524] = 0;
      v7 = v12;
      do
      {
        v8 = *(_DWORD *)v6;
        v9 = *((_DWORD *)v6 + 1);
        v10 = *((_DWORD *)v6 + 2);
        v11 = *((_DWORD *)v6 + 3);
        v6 += 16;
        *(_DWORD *)v7 = v8;
        *((_DWORD *)v7 + 1) = v9;
        *((_DWORD *)v7 + 2) = v10;
        *((_DWORD *)v7 + 3) = v11;
        v7 += 16;
      }
      while ( v6 != "}" );
      *(_WORD *)v7 = *(_WORD *)v6;
      result = httpd_cgi_ret((int)a1, v12, 33, 4);
    }
  }
  return result;
}
// 6A838C: using guessed type int __fastcall add_timer(_DWORD);
// 6A8824: using guessed type int jiffies_get(void);

