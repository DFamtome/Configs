# Custom i3 status



echo '{"verssion":1}'
echo '['

display()
{
	echo {\"full_text\" : $1\"}
}


while true; do
	time=$(date '+%H:%M')
	
	display $time
