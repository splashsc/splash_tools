int httpd_poll_init()
{
  int v0; // $a2
  int v1; // $a1
  int v2; // $v1
  int v3; // $a0
  struct pollfd *v4; // $a0
  int v5; // $t0
  struct pollfd *v6; // $v1
  char *v7; // $v0

  array_conn.fd = dword_667724;
  array_conn.events = 1;
  if ( dword_667720 == -1 )
  {
    v0 = https_fd;
    v1 = 3;
    v2 = 2;
    v3 = 1;
    if ( https_fd != -1 )
      goto LABEL_3;
LABEL_8:
    v1 = v2;
    v5 = v2;
    v2 = v3;
    goto LABEL_4;
  }
  v0 = https_fd;
  dword_6997E8 = dword_667720;
  word_6997EC = 1;
  v1 = 4;
  v2 = 3;
  v3 = 2;
  if ( https_fd == -1 )
    goto LABEL_8;
LABEL_3:
  v4 = &array_conn + v3;
  v4->fd = v0;
  v4->events = 1;
  v5 = v2 + 1;
LABEL_4:
  v6 = &array_conn + v2;
  v6->fd = gl_httpd_unix_fd;
  v6->events = 1;
  curfds = v5;
  v7 = (char *)(&array_conn + v1);
  do
  {
    *(_DWORD *)v7 = -1;
    v7 += 8;
  }
  while ( httpd_set_cookie != v7 );
  return 0;
}
// 667720: using guessed type int dword_667720;
// 667724: using guessed type int dword_667724;
// 66B5F0: using guessed type int gl_httpd_unix_fd;
// 67BD44: using guessed type int https_fd;
// 67D0A4: using guessed type int curfds;
// 6997E8: using guessed type int dword_6997E8;
// 6997EC: using guessed type __int16 word_6997EC;

