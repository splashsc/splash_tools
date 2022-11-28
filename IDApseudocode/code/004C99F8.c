int __fastcall sub_4C99F8(_DWORD *a1)
{
  const char *v2; // $v0
  char *v3; // $v1
  int v4; // $t1
  int v5; // $t0
  int v6; // $a3
  int v7; // $a2
  int result; // $v0
  char v9[1028]; // [sp+18h] [-404h] BYREF

  if ( ai_is_running(0) )
  {
    ai_unix_cgi_send(0x2728u, a1[51354], 0, 0);
    a1[52524] = 10024;
    a1[51393] = 0;
    ai_cgi_common_timeout(a1);
    result = 0;
  }
  else
  {
    v2 = "{\"code\":0,\"error\":\"\",\"data\":null}";
    v3 = v9;
    do
    {
      v4 = *(_DWORD *)v2;
      v5 = *((_DWORD *)v2 + 1);
      v6 = *((_DWORD *)v2 + 2);
      v7 = *((_DWORD *)v2 + 3);
      v2 += 16;
      *(_DWORD *)v3 = v4;
      *((_DWORD *)v3 + 1) = v5;
      *((_DWORD *)v3 + 2) = v6;
      *((_DWORD *)v3 + 3) = v7;
      v3 += 16;
    }
    while ( v2 != "}" );
    *(_WORD *)v3 = *(_WORD *)v2;
    result = httpd_cgi_ret((int)a1, v9, 33, 4);
  }
  return result;
}

