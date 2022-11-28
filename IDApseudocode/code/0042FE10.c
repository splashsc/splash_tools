int httpd_file_ext_init()
{
  void **v0; // $s0

  v0 = (void **)_httpd_cgi_all_fun;
  if ( _httpd_cgi_all_fun != &_httpd_cgi_all_fun )
  {
    do
    {
      httpd_file_ext_add((int)v0);
      v0 = (void **)*v0;
    }
    while ( v0 != &_httpd_cgi_all_fun );
  }
  return 0;
}
// 66B580: using guessed type void *_httpd_cgi_all_fun;

