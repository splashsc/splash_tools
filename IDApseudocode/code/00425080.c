int __fastcall httpd_dowith_post(int a1)
{
  int v2; // $a0
  int v3; // $v0
  char *v5; // $a1

  *(_BYTE *)(a1 + 41) = 3;
  if ( (!*(_DWORD *)(a1 + 205496)
     || (httpd_formdata_parse((_DWORD *)a1, (_BYTE *)(a1 + 564 + *(_DWORD *)(a1 + 205484)), 1), *(_BYTE *)(a1 + 41) == 3))
    && (v2 = *(_DWORD *)(a1 + 44)) != 0
    && *(_BYTE *)(v2 + 1) )
  {
    v3 = httpd_get_cgi();
    *(_DWORD *)(a1 + 205396) = v3;
    if ( v3 )
    {
      if ( !httpd_check_user(a1, *(_DWORD *)(v3 + 4)) )
        (*(void (__fastcall **)(int))(*(_DWORD *)(a1 + 205396) + 8))(a1);
    }
    else
    {
      v5 = httpd_not_found[0];
      *(_BYTE *)(a1 + 41) = 2;
      httpd_send_404_info(a1, v5, 0);
    }
  }
  else
  {
    httpd_conn_close((int *)a1);
  }
  return 0;
}
// 6676A4: using guessed type char *httpd_not_found[27];

