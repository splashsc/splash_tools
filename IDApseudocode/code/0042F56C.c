int sub_42F56C()
{
  int *v0; // $a0
  int *v1; // $s0
  int result; // $v0

  v0 = (int *)ll_httpd_conn_used;
  if ( (int *)ll_httpd_conn_used != &ll_httpd_conn_used )
  {
    do
    {
      v1 = (int *)*v0;
      result = httpd_conn_close(v0);
      v0 = v1;
    }
    while ( v1 != &ll_httpd_conn_used );
  }
  return result;
}
// 67D058: using guessed type int ll_httpd_conn_used;

