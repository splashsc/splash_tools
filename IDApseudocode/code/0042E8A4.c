void __fastcall _httpd_conn_m_free(void *a1)
{
  if ( a1 )
    _mem_free(a1);
}

