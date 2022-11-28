_DWORD *__fastcall _httpd_enter_hash(int a1, int a2)
{
  int v2; // $a0
  int v3; // $v1
  int v4; // $a2
  _DWORD *result; // $v0

  v2 = a1;
  v3 = ll_httpd_conn_hash[v2];
  v4 = a2 + 24;
  *(_DWORD *)(a2 + 24) = v3;
  if ( v3 )
    *(_DWORD *)(v3 + 4) = v4;
  result = &ll_httpd_conn_hash[v2];
  ll_httpd_conn_hash[v2] = v4;
  *(_DWORD *)(a2 + 28) = &ll_httpd_conn_hash[v2];
  return result;
}

