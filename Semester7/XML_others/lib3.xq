xquery version "1.0";
<Biblioteka>
{
for $a in /Library/book
where $a/@genre = "programming"
return
<ime genre= "{$a/@genre} ">
{$a/name/text()}
{$a/pages/text()}
</ime>
}
</Biblioteka>
