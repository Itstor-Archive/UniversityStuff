SELECT patients.first_name, patients.last_name, provinces.province_name
FROM patients
INNER JOIN provinces ON patients.province_id=provinces.province_id;