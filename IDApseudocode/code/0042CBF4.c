int _httpd_conn_all_close_socket()
{
  int *v0; // $s0
  int *v1; // $s6
  int result; // $v0

  v0 = (int *)ll_httpd_conn_used;
  if ( (int *)ll_httpd_conn_used != &ll_httpd_conn_used )
  {
    do
    {
      v1 = (int *)*v0;
      if ( v0[51354] != -1 )
      {
        httpd_conn_epoll_del((int)v0);
        close_socket(v0[51354]);
        v0[51354] = -1;
      }
      if ( v0[51355] != -1 )
      {
        httpd_conn_epoll_del_pty((int)v0);
        close_socket(v0[51355]);
        v0[51355] = -1;
      }
      result = v0[51356];
      if ( result != -1 )
      {
        httpd_conn_epoll_del_proxy((int)v0);
        result = close_socket(v0[51356]);
        v0[51356] = -1;
      }
      v0 = v1;
    }
    while ( v1 != &ll_httpd_conn_used );
  }
  return result;
}
// 67D058: using guessed type int ll_httpd_conn_used;

