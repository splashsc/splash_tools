void __fastcall jhl_httpd_just_debug_signal(int a1)
{
  syslog(7, "ll_httpd_conn_dd_num:%d\n", ll_httpd_conn_dd_num);
  syslog(7, "ll_httpd_conn_all_num:%d\n", ll_httpd_conn_all_num);
  syslog(7, "all_mem_malloc_num:%d\n", all_mem_malloc_num);
  mem_list_show();
}
// 67D0A8: using guessed type int all_mem_malloc_num;
// 67D0AC: using guessed type int ll_httpd_conn_all_num;
// 67D0B0: using guessed type int ll_httpd_conn_dd_num;

