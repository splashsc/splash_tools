int __fastcall httpd_keep_alive_timeout(int *a1)
{
  int result; // $v0

  if ( a1 )
    result = httpd_conn_close(a1);
  return result;
}

