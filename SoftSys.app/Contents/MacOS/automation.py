
import sys
import os
path = sys.argv[1] # first argument is location of web2py
#appname = sys.argv[2] # second argument is name of app
os.chdir(path)
from xml.dom import minidom
xmldoc = minidom.parse('extended.xml')
itemlist = xmldoc.getElementsByTagName('table') 
print len(itemlist)
#print itemlist[0].attributes['name'].value
i=0
c=""
for s in itemlist :
   # print s.attributes['name'].value
    c += '''def magic_'''+s.attributes['name'].value+'''():\n   '''+"grid"+"=SQLFORM.grid(db."+ s.attributes['name'].value +''',user_signature=False)\n   ''' + '''return locals()\n'''
    #print c
    i+=1
print c
log_file = open('default.py', 'w')

print>>log_file, '''# -*- coding: utf-8 -*-
# this file is released under public domain and you can use without limitations

#########################################################################
## This is a sample controller
## - index is the default action of any application
## - user is required for authentication and authorization
## - download is for downloading files uploaded in the db (does streaming)
## - api is an example of Hypermedia API support and access control
#########################################################################

def index():
    """
    example action using the internationalization operator T and flash
    rendered by views/default/index.html or views/generic.html

    if you need a simple wiki simply replace the two lines below with:
    return auth.wiki()
    """
    response.flash = T("Welcome to ")+response.title
    return dict(message=T('Hello World'))


def user():
    """
    exposes:
    http://..../[app]/default/user/login
    http://..../[app]/default/user/logout
    http://..../[app]/default/user/register
    http://..../[app]/default/user/profile
    http://..../[app]/default/user/retrieve_password
    http://..../[app]/default/user/change_password
    http://..../[app]/default/user/manage_users (requires membership in
    use @auth.requires_login()
        @auth.requires_membership('group name')
        @auth.requires_permission('read','table name',record_id)
    to decorate functions that need access control
    """
    return dict(form=auth())


@cache.action()
def download():
    """
    allows downloading of uploaded files
    http://..../[app]/default/download/[filename]
    """
    return response.download(request, db)


def call():
    """
    exposes services. for example:
    http://..../[app]/default/call/jsonrpc
    decorate with @services.jsonrpc the functions to expose
    supports xml, json, xmlrpc, jsonrpc, amfrpc, rss, csv
    """
    return service()
def magician():
    """
    exposes services. for example:
    http://..../[app]/default/call/jsonrpc
    decorate with @services.jsonrpc the functions to expose
    supports xml, json, xmlrpc, jsonrpc, amfrpc, rss, csv
    """
    return dict(message=T('Hello World'))


@auth.requires_login() 
def api():
    """
    this is example of API with access control
    WEB2PY provides Hypermedia API (Collection+JSON) Experimental
    """
    from gluon.contrib.hypermedia import Collection
    rules = {
        '<tablename>': {'GET':{},'POST':{},'PUT':{},'DELETE':{}},
        }
    return Collection(db).process(request,response,rules)\n''' + c 

  



log_file.close()























#print itemlist[0].attributes['name'].value
i=0
d=""
for sa in itemlist:
    d += "\n"+'''{{=A(T("'''+sa.attributes['name'].value+'''"), _href=URL(response.title,'default','magic_'''+ sa.attributes['name'].value+''''))}}'''+"\n"
    i+1
print d


log_file1 = open('magician.html', 'w')
print>>log_file1, '''{{extend 'layout.html'}}
<h1>SoftSys CRUD Interface</h1>'''+ d+ "\n"+'''{{=BEAUTIFY(response._vars)}}'''

log_file1.close()


