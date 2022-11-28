__pid_t sub_42FB54()
{
  __pid_t result; // $v0
  int *v1; // $v1

LABEL_1:
  while ( 1 )
  {
    result = wait_any_nohang(0);
    if ( result <= 0 )
      return result;
    while ( 1 )
    {
      v1 = (int *)ll_httpd_conn_pty;
      if ( (int *)ll_httpd_conn_pty == &ll_httpd_conn_pty )
        break;
      if ( result != *(_DWORD *)(ll_httpd_conn_pty + 205448) )
      {
        do
        {
          v1 = (int *)*v1;
          if ( v1 == &ll_httpd_conn_pty )
            goto LABEL_1;
        }
        while ( result != v1[51362] );
      }
      v1[51362] = -1;
      if ( v1 == (int *)8 )
        goto LABEL_1;
      httpd_conn_close(v1 - 2);
      result = wait_any_nohang(0);
      if ( result <= 0 )
        return result;
    }
  }
}
// 67D068: using guessed type int ll_httpd_conn_pty;

