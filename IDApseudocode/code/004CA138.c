int __fastcall https_ssl_uninit(int a1)
{
  int result; // $v0

  if ( a1 )
    https_conn_clear();
  result = ERR_free_strings();
  if ( https_ssl_ctx )
  {
    result = SSL_CTX_free();
    https_ssl_ctx = 0;
  }
  return result;
}
// 681504: using guessed type int https_ssl_ctx;
// 6A833C: using guessed type int SSL_CTX_free(void);
// 6A85C0: using guessed type int ERR_free_strings(void);

