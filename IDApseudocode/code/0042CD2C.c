int exit_clean()
{
  if ( dword_667724 != -1 )
  {
    close_socket(dword_667724);
    dword_667724 = -1;
  }
  if ( dword_667720 != -1 )
  {
    close_socket(dword_667720);
    dword_667720 = -1;
  }
  if ( https_fd != -1 )
  {
    close_socket(https_fd);
    https_fd = -1;
  }
  https_ssl_uninit(0);
  _httpd_conn_all_close_socket();
  return _httpd_mem_clean();
}
// 667720: using guessed type int dword_667720;
// 667724: using guessed type int dword_667724;
// 67BD44: using guessed type int https_fd;

