int https_conn_clear()
{
  int *v0; // $a0
  int *v1; // $s0

  v0 = (int *)ll_httpd_conn_used;
  v1 = *(int **)ll_httpd_conn_used;
  if ( (int *)ll_httpd_conn_used != &ll_httpd_conn_used )
  {
    while ( 1 )
    {
      if ( v0[52496] )
        httpd_conn_close(v0);
      v0 = v1;
      if ( v1 == &ll_httpd_conn_used )
        break;
      v1 = (int *)*v1;
    }
  }
  return 0;
}
// 67D058: using guessed type int ll_httpd_conn_used;

