int *__fastcall _httpd_conn_find(int a1)
{
  _DWORD *v1; // $v1
  int *result; // $v0
  int *v3; // $v1
  int *v4; // $v1

  v1 = (_DWORD *)ll_httpd_conn_hash[a1 & 0xFFF];
  if ( !v1 )
    goto LABEL_6;
  if ( a1 != v1[51348] )
  {
    while ( 1 )
    {
      v1 = (_DWORD *)*v1;
      if ( !v1 )
        break;
      if ( a1 == v1[51348] )
      {
        result = v1 - 6;
        goto LABEL_18;
      }
    }
LABEL_6:
    v3 = (int *)ll_httpd_conn_pty;
    if ( (int *)ll_httpd_conn_pty != &ll_httpd_conn_pty )
    {
      if ( a1 == *(_DWORD *)(ll_httpd_conn_pty + 205412) )
      {
LABEL_19:
        result = v3 - 2;
        v3[51351] = a1;
        return result;
      }
      while ( 1 )
      {
        v3 = (int *)*v3;
        if ( v3 == &ll_httpd_conn_pty )
          break;
        if ( a1 == v3[51353] )
          goto LABEL_19;
      }
    }
    v4 = (int *)fbss;
    if ( (int *)fbss != &fbss )
    {
      if ( a1 == *(_DWORD *)(fbss + 205408) )
      {
LABEL_20:
        result = v4 - 4;
        v4[51349] = a1;
        return result;
      }
      while ( 1 )
      {
        v4 = (int *)*v4;
        if ( v4 == &fbss )
          break;
        if ( a1 == v4[51352] )
          goto LABEL_20;
      }
    }
    return 0;
  }
  result = v1 - 6;
LABEL_18:
  v1[51347] = a1;
  return result;
}
// 67D050: using guessed type int fbss;
// 67D068: using guessed type int ll_httpd_conn_pty;

