import json

dict = {
    'name':
    'switch',
    'description':
    'Transactions file received from YCS',
    'docs': {
        'show': True
    },
    'config': {
        'materialized': 'incremental'
    },
    'columns': [{
        'name': 'id',
        'description': 'It is unique for a particular transaction.',
        'tests': ['not_null'],
        'data_type': 'serial4'
    }, {
        'name': 'record_indicator',
        'description': 'record indiacator for particular transaction',
        'data_type': 'varchar(12)'
    }, {
        'name': 'card_no',
        'description': 'card number related with the transaction',
        'data_type': 'varchar(19)'
    }, {
        'name': 'trace_no',
        'description': 'trace number for the transaction',
        'data_type': 'varchar(6)'
    }, {
        'name': 'processing_code',
        'description': 'processing_code for the transaction',
        'data_type': 'varchar(6)'
    }, {
        'name': 'trans_type',
        'description': 'type of transaction',
        'data_type': 'varchar(25)'
    }, {
        'name': 'retrieval_ref_num',
        'description': 'retrieval ref number related with the transaction',
        'data_type': 'varchar(12)'
    }, {
        'name': 'terminal_id',
        'description': 'terminal id related with the transaction',
        'data_type': 'varchar(8)'
    }, {
        'name': 'merchant_id',
        'description': 'merchant id related with the transaction',
        'data_type': 'varchar(15)'
    }, {
        'name': 'acquirer_member_id',
        'description': 'acquirer member id related with the transaction',
        'data_type': 'varchar(10)'
    }, {
        'name': 'merchant_name',
        'description': 'merachnat name',
        'data_type': 'varchar(50)'
    }, {
        'name': 'local_trans_date',
        'description': 'date of the transaction',
        'data_type': 'varchar(8)'
    }, {
        'name': 'local_trans_time',
        'description': 'time of the transaction',
        'data_type': 'varchar(6)'
    }, {
        'name': 'merchant_category_code',
        'description': None,
        'data_type': 'varchar(4)'
    }, {
        'name': 'transaction_channel',
        'description': None,
        'data_type': 'varchar(4)'
    }, {
        'name': 'trx_amt',
        'description': None,
        'data_type': 'varchar(12)'
    }, {
        'name': 'trx_currency',
        'description': None,
        'data_type': 'varchar(3)'
    }, {
        'name': 'bill_amt',
        'description': None,
        'data_type': 'varchar(12)'
    }, {
        'name': 'bill_currency',
        'description': None,
        'data_type': 'varchar(3)'
    }, {
        'name': 'authorization_id',
        'description': None,
        'data_type': 'varchar(6)'
    }, {
        'name': 'response_code',
        'description': None,
        'data_type': 'varchar(6)'
    }, {
        'name': 'reversal_flag',
        'description': None,
        'data_type': 'varchar(1)'
    }, {
        'name': 'transaction_mode',
        'description': None,
        'data_type': 'varchar(3)'
    }, {
        'name': 'transaction_fee',
        'description': 'varchar(12)',
        'data_type': None
    }, {
        'name': 'proxy_number',
        'description': None,
        'data_type': 'varchar(12)'
    }, {
        'name': 'transaction_reference_number',
        'description': None,
        'data_type': 'varchar(37)'
    }, {
        'name': 'agent_type',
        'description': None,
        'data_type': 'varchar(12)'
    }, {
        'name': 'product_code',
        'description': None,
        'data_type': 'varchar(6)'
    }, {
        'name': 'message_type',
        'description': None,
        'data_type': 'varchar(4)'
    }, {
        'name': 'transaction_date',
        'description': None,
        'data_type': 'timestamp'
    }, {
        'name': 'loaddate',
        'description': None,
        'data_type': 'date'
    }, {
        'name': 'card_hash_id',
        'description': None,
        'data_type': 'varchar(64)'
    }]
}

# {
#     "metadata": [
#         {
#             "breadcrumb": [],
#             "metadata": {
#                 "table-key-properties": []
#             }
#         },
#         {
#             "breadcrumb": [
#                 "properties",
#                 "id"
#             ],
#             "metadata": {
#                 "inclusion": "available",
#             }
#         },
#         {
#             "breadcrumb": [
#                 "properties",
#                 "record_indicator"
#             ],
#             "metadata": {
#                 "inclusion": "available",
#             }
#         }
#     ]
# }


def convert_to_json(dict):
    json = {}
    json["metadata"] = []
    json["metadata"].append({
        "breadcrumb": [],
        "metadata": {
            "table-key-properties": []
        }
    })
    for i in dict["columns"]:
        json["metadata"].append({
            "breadcrumb": ["properties", i["name"]],
            "metadata": {
                "inclusion": "available"
            }
        })
    return json


print(convert_to_json(dict))

with open('data1.json', 'w') as outfile:
    json.dump(convert_to_json(dict), outfile)
