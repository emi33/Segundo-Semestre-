create user 'emiliano' identified by 'manager';
show databases;
grant all privileges on *.* to 'emiliano' with grant option;
show databases;
use fincas;
select * from especies;
revoke all privileges, grant option from 'emiliano';
show databases;
-- SET GLOBAL validate_password.policy=LOW;