int httpd_release_caches()
{
  sync();
  sync();
  return system("echo 3 > /proc/sys/vm/drop_caches");
}

