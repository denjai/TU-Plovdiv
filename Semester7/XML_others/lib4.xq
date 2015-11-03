xquery version "1.0";
<Biblioteka>
{
for $a in /Library/book/author
return
<avtor>
{$a/name}
{$a/fam}
{
for $b in /Library/book
where $b/author  =  $a 
return 
<kniga>
{ $b/name/text()}
</kniga>
}
</avtor>
}
</Biblioteka>

