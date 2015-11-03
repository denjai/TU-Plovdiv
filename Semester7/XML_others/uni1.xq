xquery version "1.0";
<uni>
{
for $a in /Uni/StudentGroup/Name/Student
return
<ime>
{$a/name/text()}
{" "}
{$a/fam/text()}
{" "}
 {$a/deptID/text()}
</ime>
 {
for $b in /Uni/StudentGroup/Lection
<grName>
     {$b/group/text()}
</grName>
}
}
</uni>