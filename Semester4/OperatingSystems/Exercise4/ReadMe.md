###Задачи:
Да се състави конзолно приложение на C, което:
* създадава динамично масив от threadinfo (описана по-горе) с размерравен на броя на нишките. Масивът да не е глобален.
* създава няколко нишки (броят се въвежда от потребителя), като HANDLEи TID на всяка нишка се съхранява в масива.
* за всяка thread фуннкция да се предава като неин параметър указател къмсъответния елемент threadinfo с данните за нишката.
* в thread функцията на нишките се превърта празен цикъл с произволенброй итерации (поне няколко хиляди) и накрая се извежда съобщение “thread X terminated”, където X е TID на съответната нишка.
* главната нишка накрая също извежда съобщение “main thread terminated”
