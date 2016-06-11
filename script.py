#!/usr/bin/env python
#-*- coding: utf-8 -*-

import smtplib
from email.MIMEMultipart import MIMEMultipart
from email.MIMEText import MIMEText

msg = MIMEMultipart()
msg['From'] = 'scluckas@gmail.com'
msg['To'] = 'lucas@hackwrld.com; scluckas@gmail.com'
msg['Subject'] = 'Quelques problèmes'
message = "Bonjour,\n\
Il faut visiblement vous réclamer les choses régulièrement pour les obtenir.\n\
C'est pourquoi maintenant, je vous envoie ce mail quotidiennement avec l'espoir que mes problèmes soient enfin résolus.\n\
\n\
			- J'attends depuis mon arrivée dans l'appartement un double des clés, vous m'avez plusieurs fois dit que je l'aurai. J'attends toujours..\n\
			- Il y a également les 1600E que j'ai versé pour la réparation du coffret éléctrique. De tels frais ne sont pas à la charge du locataire !\n\
			- Depuis les travaux, il y a une fuite dans les toilettes, merci d'intervenir rapidement,\n\
			- Depuis la réparation du coffret (QUE J'AI PAYÉ), le compteur jour/nuit n'à toujours pas été remis,\n\
			- Le problème d'humidité dans l'appartement n'est toujours pas résolu et s'étends dans la pièce principale.\n\
\n\
Très respectueusement,\n\
Lucas"
msg.attach(MIMEText(message))
mailserver = smtplib.SMTP('smtp.gmail.com', 587)
mailserver.ehlo()
mailserver.starttls()
mailserver.ehlo()
mailserver.login('scluckas@gmail.com', 'F8Lz=kTg')
mailserver.sendmail('scluckas@gmail.com', 'scluckas@gmail.com', msg.as_string())
mailserver.quit()
